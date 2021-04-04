#include "kernal.h"

#include "../common/ray_sample.h"

namespace {

__global__ void kernal(const Vec3f *n, Vec3f *wi, float *throughput, int size) {
  int index = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  for (int i = index; i < size; i += stride) {
    raySample(i, n[i], wi[i], throughput[i]);
  }
}

} // namespace

namespace gpu {

void dispatchKernal(const Vec3f *n, Vec3f *wi, float *throughput, int size) {
  const int blockSize = 256;
  const int numBlocks = (size + blockSize - 1) / blockSize;

  kernal<<<numBlocks, blockSize>>>(n, wi, throughput, size);

  cudaDeviceSynchronize();
}

} // namespace gpu
