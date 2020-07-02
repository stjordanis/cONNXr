//this file was generated by ../../../../../scripts/onnx_generator/OperatorInfo.py
#include "operators/operator_info.h"
#include "operators/onnx/operator__onnx__leakyrelu__6.h"

/* attributes */
static
operator_info_attribute
attributes[] = {
{
    .name     = "alpha",
    .optional = false,
    .type     = ONNX__ATTRIBUTE_PROTO__ATTRIBUTE_TYPE__FLOAT
}
};

/* input tensors */
static
uint32_t
tensor_type_X[] = {
ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE,
ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT,
ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16
};

static
operator_info_tensor
inputs[] = {
{
    .name        = "X",
    .optional    = false,
    .variadic    = false,
    .homogeneous = true,
    .constraint  = "T",
    .n_types     = 3,
    .types       = tensor_type_X
}
};

/* output tensors */
static
uint32_t
tensor_type_Y[] = {
ONNX__TENSOR_PROTO__DATA_TYPE__DOUBLE,
ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT,
ONNX__TENSOR_PROTO__DATA_TYPE__FLOAT16
};

static
operator_info_tensor
outputs[] = {
{
    .name        = "Y",
    .optional    = false,
    .variadic    = false,
    .homogeneous = true,
    .constraint  = "T",
    .n_types     = 3,
    .types       = tensor_type_Y
}
};

/* constraints */
static
operator_info_constraint
constraints[] = {
{ "T" }
};

/* operator info */
operator_info
info_operator__onnx__leakyrelu__6 = {
    .name         = "LeakyRelu",
    .range_input  = { 1, 1 },
    .range_output = { 1, 1 },
    .n_attribute  = 1,
    .attribute    = attributes,
    .n_input      = 1,
    .input        = inputs,
    .n_output     = 1,
    .output       = outputs,
    .n_constraint = 1,
    .constraint   = constraints
};