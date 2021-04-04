#include "common/distribution.h"
#include "common/random.h"
#include "common/vector.h"
#include "cpu/kernal.h"
#include "defines.h"
#include "gpu/info.h"
#include "gpu/kernal.h"

#include <algorithm>
#include <cstdio>
#include <numeric>

// Pick a random size for computation (1000th prime number)
constexpr int size = 7919;

int main() {
#ifdef __CUDACC__
  gpu::info();
#endif

  // Input to the computation
  auto n = static_cast<Vec3f *>(ALLOCATE(sizeof(Vec3f) * size));

  for (int i = 0; i < size; ++i) {
    auto state = pcg(pcg(i) + 0);

    float u[2];

    state = pcg(state);
    u[0] = pcgFloat(state);

    state = pcg(state);
    u[1] = pcgFloat(state);

    Vec3f normal;
    latitudeLongitudeMapping(u, normal);

    n[i] = normal;
  }

  // Output of the computation
  auto wi = static_cast<Vec3f *>(ALLOCATE(sizeof(Vec3f) * size));
  auto throughput = static_cast<float *>(ALLOCATE(sizeof(float) * size));

  auto zero = [](float *array, int size) { std::fill_n(array, size, 0.0f); };
  auto sumv = [](float *array, int size) {
    return std::accumulate(array, array + size, 0.0f);
  };

  zero(throughput, size);
  cpu::dispatchKernal(n, wi, throughput, size);
  printf("CPU throughput is equal to %f\n", sumv(throughput, size) / size);

#ifdef __CUDACC__
  zero(throughput, size);
  gpu::dispatchKernal(n, wi, throughput, size);
  printf("GPU throughput is equal to %f\n", sumv(throughput, size) / size);
#endif

  zero(throughput, size);
  printf("Verify zero lambda: %f\n", sumv(throughput, size));

  FREE(n);
  FREE(wi);
  FREE(throughput);

  return 0;
}
