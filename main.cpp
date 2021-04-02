#include "cpu/kernal.h"
#include "defines.h"
#include "gpu/kernal.h"
#include "info.h"

#include <algorithm>
#include <cstdio>
#include <numeric>

// Pick a random size for computation (20th prime number)
constexpr int size = 113;

int main() {
  info();

  auto argA = static_cast<float *>(ALLOCATE(sizeof(float) * size));
  auto argB = static_cast<float *>(ALLOCATE(sizeof(float) * size));
  auto argC = static_cast<float *>(ALLOCATE(sizeof(float) * size));

  for (int i = 0; i < size; ++i) {
    argA[i] = i;
    argB[i] = i * 2;
  }

  auto zero = [](float *array, int size) { std::fill_n(array, size, 0.0f); };
  auto sumv = [](float *array, int size) {
    return std::accumulate(array, array + size, 0.0f);
  };

  zero(argC, size);
  cpu::kernal(argA, argB, argC, size);
  printf("CPU sum is equal to %f\n", sumv(argC, size));

  zero(argC, size);
  gpu::kernal(argA, argB, argC, size);
  printf("GPU sum is equal to %f\n", sumv(argC, size));

  zero(argC, size);
  printf("Verify zero lambda: %f\n", sumv(argC, size));

  FREE(argA);
  FREE(argB);
  FREE(argC);

  return 0;
}
