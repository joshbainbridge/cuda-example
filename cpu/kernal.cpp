#include "kernal.h"

#include "../common/ray_sample.h"

namespace {

void kernal(const Vec3f *n, Vec3f *wi, float *throughput, int size) {
  int index = 0;
  int stride = 1;

  for (int i = index; i < size; i += stride) {
    raySample(i, n[i], wi[i], throughput[i]);
  }
}

} // namespace

namespace cpu {

void dispatchKernal(const Vec3f *n, Vec3f *wi, float *throughput, int size) {
  kernal(n, wi, throughput, size);
}

} // namespace cpu
