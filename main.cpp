#include "common/bsdf.h"
#include "common/scene.h"
#include "common/vector.h"
#include "cpu/kernals.h"
#include "defines.h"
#include "gpu/info.h"
#include "gpu/kernals.h"

#include <algorithm>
#include <cstdio>
#include <numeric>

// Pick a random size for computation (1000th prime number)
constexpr int size = 7919;

//#define PRINT_INFO

int main() {
#ifdef __CUDACC__
#ifdef PRINT_INFO
  gpu::info();
#endif
#endif

  auto scene = static_cast<Scene *>(ALLOCATE(sizeof(Scene)));
  auto bsdf = static_cast<BsdfPtr *>(ALLOCATE(sizeof(BsdfPtr) * size));
  auto ng = static_cast<Vec3f *>(ALLOCATE(sizeof(Vec3f) * size));
  auto wi = static_cast<Vec3f *>(ALLOCATE(sizeof(Vec3f) * size));
  auto f = static_cast<float *>(ALLOCATE(sizeof(float) * size));

  auto zero = [](float *array, int size) { std::fill_n(array, size, 0.0f); };
  auto sumv = [](float *array, int size) {
    return std::accumulate(array, array + size, 0.0f);
  };

  zero(f, size);
  cpu::buildScene(scene);
  cpu::generateHits(scene, ng, bsdf, size);
  cpu::sampleRays(ng, bsdf, wi, f, size);
  cpu::destroyScene(scene);
  printf("CPU 'f' is equal to %f\n", sumv(f, size) / size);

#ifdef __CUDACC__
  zero(f, size);
  gpu::buildScene(scene);
  gpu::generateHits(scene, ng, bsdf, size);
  gpu::sampleRays(ng, bsdf, wi, f, size);
  gpu::destroyScene(scene);
  printf("GPU 'f' is equal to %f\n", sumv(f, size) / size);
#endif

  zero(f, size);
  printf("Verify zero lambda: %f\n", sumv(f, size));

  FREE(scene);
  FREE(bsdf);
  FREE(ng);
  FREE(wi);
  FREE(f);

  return 0;
}
