#include "kernal.h"

#include "../common/add_float.h"

namespace {

__global__ void kernal(const float *a, const float *b, float *c, int size) {
  int index = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  for (int i = index; i < size; i += stride) {
    c[i] = addFloat(a[i], b[i]);
  }
}

} // namespace

namespace gpu {

void dispatchKernal(const float *a, const float *b, float *c, int size) {
  const int blockSize = 256;
  const int numBlocks = (size + blockSize - 1) / blockSize;

  kernal<<<numBlocks, blockSize>>>(a, b, c, size);
  cudaDeviceSynchronize();
}

} // namespace gpu
