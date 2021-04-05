#include "kernals.h"

#include "../common/generate_hit.h"
#include "../common/ray_sample.h"

constexpr int blockSize = 256;
constexpr int numBlocks = 8;

namespace {
namespace kernals {

__global__ void buildScene(Scene *scene) { ::buildScene(scene); }

__global__ void destroyScene(Scene *scene) { ::destroyScene(scene); }

__global__ void generateHits(const Scene *scene, Hit *hit, int size) {
  const int index = blockIdx.x * blockDim.x + threadIdx.x;
  const int stride = blockDim.x * gridDim.x;

  for (int i = index; i < size; i += stride) {
    generateHit(i, *scene, hit[i]);
  }
}

__global__ void sampleRays(const Hit *hit, Vec3f *wi, float *f, int size) {
  const int index = blockIdx.x * blockDim.x + threadIdx.x;
  const int stride = blockDim.x * gridDim.x;

  for (int i = index; i < size; i += stride) {
    raySample(i, hit[i], wi[i], f[i]);
  }
}

} // namespace kernals
} // namespace

namespace gpu {

void buildScene(Scene *scene) { kernals::buildScene<<<1, 1>>>(scene); }

void destroyScene(Scene *scene) { kernals::destroyScene<<<1, 1>>>(scene); }

void generateHits(const Scene *scene, Hit *hit, int size) {
  kernals::generateHits<<<numBlocks, blockSize>>>(scene, hit, size);
}

void sampleRays(const Hit *hit, Vec3f *wi, float *f, int size) {
  kernals::sampleRays<<<numBlocks, blockSize>>>(hit, wi, f, size);
}

} // namespace gpu
