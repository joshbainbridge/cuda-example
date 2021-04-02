#include "kernal.h"

#include "../common/add_float.h"

namespace {

__global__ void dispatch(const float *argA, const float *argB, float *argC) {
  int tid = blockIdx.x;

  argC[tid] = addFloat(argA[tid], argB[tid]);
}

} // namespace

namespace gpu {

void kernal(const float *argA, const float *argB, float *argC, int size) {
  dispatch<<<size, 1>>>(argA, argB, argC);
  cudaDeviceSynchronize();
}

} // namespace gpu
