//this file was generated by ../../../../../../scripts/onnx_generator/OperatorTypeResolver.py
#include "operators/ai.onnx/Constant/12/operator__ai_onnx__constant__12.h"
#include "operators/operator_stub.h"
#include <inttypes.h>
#include <stdio.h>

operator_executer resolve_operator__ai_onnx__constant__12(
    node_context *ctx
){
    operator_executer executer = NULL;
    {
    /* skipping constraint check, because no constraint exist */
    executer = &operator__ai_onnx__constant__12;
}
    if (!executer) {
        executer = &operator_stub;
    }
    return executer;
}