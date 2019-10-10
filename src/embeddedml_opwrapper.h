#ifndef EMBEDDEDML_OPWRAPPER_H
#define EMBEDDEDML_OPWRAPPER_H
#include "onnx.pb-c.h"

// Default set of operator ai.onnx
void Operators_Abs(void *todo);
void Operators_Acos(void *todo);
void Operators_Acosh(void *todo);
void Operators_Add(void *inOut, void *matrix, int m, enum _Onnx__TensorProto__DataType type);
void Operators_And(void *todo);
void Operators_ArgMax(void *todo);
void Operators_ArgMin(void *todo);
void Operators_Asin(void *todo);
void Operators_Asinh(void *todo);
void Operators_Atan(void *todo);
void Operators_Atanh(void *todo);
void Operators_AveragePool(void *todo);
void Operators_BatchNormalization(void *todo);
void Operators_BitShift(void *todo);
void Operators_Cast(void *in, void *out, enum _Onnx__TensorProto__DataType inType, enum _Onnx__TensorProto__DataType outType);
void Operators_Ceil(void *todo);
void Operators_Clip(void *todo);
void Operators_Compress(void *todo);
void Operators_Concat(void *todo);
void Operators_ConcatFromSequence(void *todo);
void Operators_Constant(void *todo);
void Operators_ConstantOfShape(void *todo);
void Operators_Conv(void *todo);
void Operators_ConvInteger(void *todo);
void Operators_ConvTranspose(void *todo);
void Operators_Cos(void *todo);
void Operators_Cosh(void *todo);
void Operators_CumSum(void *todo);
void Operators_DepthToSpace(void *todo);
void Operators_DequantizeLinear(void *todo);
void Operators_Det(void *todo);
void Operators_Div(void *todo);
void Operators_Dropout(void *todo);
void Operators_Elu(void *todo);
void Operators_Equal(void *todo);
void Operators_Erf(void *todo);
void Operators_Exp(void *todo);
void Operators_Expand(void *todo);
void Operators_EyeLike(void *todo);
void Operators_Flatten(void *todo);
void Operators_Floor(void *todo);
void Operators_GRU(void *todo);
void Operators_Gather(void *todo);
void Operators_GatherElements(void *todo);
void Operators_GatherND(void *todo);
void Operators_Gemm(void *todo);
void Operators_GlobalAveragePool(void *todo);
void Operators_GlobalLpPool(void *todo);
void Operators_GlobalMaxPool(void *todo);
void Operators_Greater(void *todo);
void Operators_HardSigmoid(void *todo);
void Operators_Hardmax(void *todo);
void Operators_Identity(void *todo);
void Operators_If(void *todo);
void Operators_InstanceNormalization(void *todo);
void Operators_IsInf(void *todo);
void Operators_IsNaN(void *todo);
void Operators_LRN(void *todo);
void Operators_LSTM(void *todo);
void Operators_LeakyRelu(void *todo);
void Operators_Less(void *todo);
void Operators_Log(void *todo);
void Operators_LogSoftmax(void *todo);
void Operators_Loop(void *todo);
void Operators_LpNormalization(void *todo);
void Operators_LpPool(void *todo);
void Operators_MatMul(void *in, void *matrix, int m, int n, int k, void *out, enum _Onnx__TensorProto__DataType type);
void Operators_MatMulInteger(void *todo);
void Operators_Max(void *todo);
void Operators_MaxPool(void *todo);
void Operators_MaxRoiPool(void *todo);
void Operators_MaxUnpool(void *todo);
void Operators_Mean(void *todo);
void Operators_Min(void *todo);
void Operators_Mod(void *todo);
void Operators_Mul(void *todo);
void Operators_Multinomial(void *todo);
void Operators_Neg(void *todo);
void Operators_NonMaxSuppression(void *todo);
void Operators_NonZero(void *todo);
void Operators_Not(void *todo);
void Operators_OneHot(void *todo);
void Operators_Or(void *todo);
void Operators_PRelu(void *todo);
void Operators_Pad(void *todo);
void Operators_Pow(void *todo);
void Operators_QLinearConv(void *todo);
void Operators_QLinearMatMul(void *todo);
void Operators_QuantizeLinear(void *todo);
void Operators_RNN(void *todo);
void Operators_RandomNormal(void *todo);
void Operators_RandomNormalLike(void *todo);
void Operators_RandomUniform(void *todo);
void Operators_RandomUniformLike(void *todo);
void Operators_Reciprocal(void *todo);
void Operators_ReduceL1(void *todo);
void Operators_ReduceL2(void *todo);
void Operators_ReduceLogSum(void *todo);
void Operators_ReduceLogSumExp(void *todo);
void Operators_ReduceMax(void *todo);
void Operators_ReduceMean(void *todo);
void Operators_ReduceMin(void *todo);
void Operators_ReduceProd(void *todo);
void Operators_ReduceSum(void *todo);
void Operators_ReduceSumSquare(void *todo);
void Operators_Relu(float *inOut, int size);
void Operators_Reshape(void *todo);
void Operators_Resize(void *todo);
void Operators_ReverseSequence(void *todo);
void Operators_RoiAlign(void *todo);
void Operators_Round(void *todo);
void Operators_Scan(void *todo);
void Operators_Scatter(void *todo);
void Operators_ScatterElements(void *todo);
void Operators_ScatterND(void *todo);
void Operators_Selu(void *todo);
void Operators_SequenceAt(void *todo);
void Operators_SequenceConstruct(void *todo);
void Operators_SequenceEmpty(void *todo);
void Operators_SequenceErase(void *todo);
void Operators_SequenceInsert(void *todo);
void Operators_SequenceLength(void *todo);
void Operators_Shape(void *todo);
void Operators_Shrink(void *todo);
void Operators_Sigmoid(void *x, int size);
void Operators_Sign(void *todo);
void Operators_Sin(void *todo);
void Operators_Sinh(void *todo);
void Operators_Size(void *todo);
void Operators_Slice(void *todo);
void Operators_Softmax(void *x, int dimx, int dimy);
void Operators_Softplus(void *todo);
void Operators_Softsign(void *todo);
void Operators_SpaceToDepth(void *todo);
void Operators_Split(void *todo);
void Operators_SplitToSequence(void *todo);
void Operators_Sqrt(void *todo);
void Operators_Squeeze(void *todo);
void Operators_StringNormalizer(void *todo);
void Operators_Sub(void *todo);
void Operators_Sum(void *todo);
void Operators_Tan(void *todo);
void Operators_Tanh(void *todo);
void Operators_TfIdfVectorizer(void *todo);
void Operators_ThresholdedRelu(void *todo);
void Operators_Tile(void *todo);
void Operators_TopK(void *todo);
void Operators_Transpose(void *todo);
void Operators_Unique(void *todo);
void Operators_Unsqueeze(void *todo);
void Operators_Upsample(void *todo);
void Operators_Where(void *todo);
void Operators_Xor(void *todo);

#endif
