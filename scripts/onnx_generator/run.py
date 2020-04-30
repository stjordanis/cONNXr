import os
import sys
import re
import pathlib
from .OperatorHeader import OperatorHeader
from .OperatorTypeResolver import OperatorTypeResolver
from .OperatorSanityCheck import OperatorSanityCheck
from .OperatorSets import OperatorSets
from .OnnxWrapper import OnnxSchema
from . import args

def note(text, verbosity=0 ):
    if verbosity <= args.verbose:
        print(text)

def warning(text, verbosity=0):
    if verbosity <= args.verbose:
        print(text, file=sys.stderr)

def fatal(text, error=1):
    print(text, file=sys.stderr)
    sys.exit(error)

if args.onnx:
    sys.path.insert(0, os.path.realpath(args.onnx[0]))
    try:
        import onnx_cpp2py_export
    except:
        fatal("could not import onnx_cpp2py_export!")
else:
    try:
        from onnx import onnx_cpp2py_export
    except:
        fatal("could not import onnx_cpp2py_export from onnx!")

all_schemas = [ OnnxSchema(s) for s in onnx_cpp2py_export.defs.get_all_schemas_with_history()]
num_schemas = len(all_schemas)

domain2name2version2schema = {}
for schema in all_schemas:
    name2version2schema = domain2name2version2schema.setdefault(schema.domain,{})
    version2schema = name2version2schema.setdefault(schema.name,{})
    version2schema[schema.version] = schema

note("selecting domains")
domains = domain2name2version2schema.keys()
note(f"onnx operator schemas have {len(domains)} domains: {', '.join(domains)}",2)
if "all" in args.domains:
    domains = domains
else:
    domains = set(args.domains)

delete_domains = []
for domain in domain2name2version2schema.keys():
    if domain in domains:
        note(f"including domain '{domain}'",2)
    else:
        note(f"excluding domain '{domain}'",3)
        delete_domains.append(domain)
for domain in delete_domains:
    del domain2name2version2schema[domain]

note("including onnx operator schemas",1)
delete_names = {}
for domain, name2version2schema in domain2name2version2schema.items():
    for name in name2version2schema.keys():
        included = False
        for pattern in set(args.include):
            if re.match(pattern,name):
                note(f"included '{domain}' operator schema '{name}' by pattern '{pattern}'",2)
                included = True
                break
        if not included:
            note(f"no pattern included '{domain}' operator schema {name}",3)
            delete_names.setdefault(domain,[]).append(name)
for domain, names in delete_names.items():
    for name in names:
        del domain2name2version2schema[domain][name]

note("excluding onnx operator schemas",1)
delete_names = {}
for domain, name2version2schema in domain2name2version2schema.items():
    for name in name2version2schema.keys():
        excluded = False
        for pattern in args.exclude:
            if re.match(pattern,name):
                note(f"excluded '{domain}' operator schema '{name}' by pattern '{pattern}'",2)
                excluded = True
                delete_names.setdefault(domain,[]).append(name)
                break
        if not excluded:
            note(f"no pattern excluded '{domain}' operator schema {name}",3)
for domain, names in delete_names.items():
    for name in names:
        del domain2name2version2schema[domain][name]

note("selecting onnx operator schema versions")
delete_versions = {}
for domain, name2version2schema in domain2name2version2schema.items():
    for name, version2schema in name2version2schema.items():
        versions = version2schema.keys()
        note(f"'{domain}' operator schema '{name}' has {len(versions)} version(s): {', '.join([str(v) for v in versions])}",2)
        if args.version[-1] == "all":
            versions = versions
        elif args.version[-1] == "latest":
            versions = [max(versions)]
        else:
            for version in range(int(args.version[-1]),0,-1):
                if version in versions:
                    versions = [version]
                    break
        for version in version2schema.keys():
            if version in versions:
                note(f"included '{domain}' operator schema '{name}' version {version}",2)
            else:
                note(f"excluded '{domain}' operator schema '{name}' version {version}",3)
                delete_versions.setdefault(domain,{}).setdefault(name,[]).append(version)
for domain, name2version in delete_versions.items():
    for name, versions in name2version.items():
        for version in versions:
            del domain2name2version2schema[domain][name][version]


schemas = []
for name2version2schema in domain2name2version2schema.values():
    for version2schema in name2version2schema.values():
        for schema in version2schema.values():
            schemas.append(schema)

note("generating onnx operator headers")
path = f"{args.path[-1]}/{args.header[-1]}/"
headers = [ OperatorHeader(s,path) for s in schemas ]
note("generating onnx operator type resolvers")
path = f"{args.path[-1]}/{args.resolve[-1]}/"
resolvers = [ OperatorTypeResolver(s,path) for s in schemas ]
note("generating onnx operator sanity checks")
path = f"{args.path[-1]}/{args.check[-1]}/"
checks = [ OperatorSanityCheck(s,path) for s in schemas ]
note("generating onnx operator sets")
path = f"{args.path[-1]}/{args.sets[-1]}/"
sets = OperatorSets(headers,path)

files = []
if not args.no_header:
    for h in headers:
        files.append(h)
if not args.no_resolve:
    for r in resolvers:
        files.append(r)
if not args.no_check:
    for c in checks:
        files.append(c)
if not args.no_sets:
    files.append(sets)

writecount = 0
note("Writing files",1)
if not args.path[-1]:
    warning("skipping write because args.path is not set")
else:
    for obj in files:
        path = obj.filename().resolve()
        if path.exists() and not args.force:
            warning(f"skipping existing file '{path}'",1)
            continue
        note(f"writing file {path}",3)
        os.makedirs(path.parent,exist_ok=True)
        path.open("w").write(obj.text())
        writecount += 1
note(f"wrote {writecount} of {len(files)} files")