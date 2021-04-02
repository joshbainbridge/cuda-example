#include "kernal.h"

#include "../common/add_float.h"

namespace {

void kernal(const float *a, const float *b, float *c, int size) {
  int index = 0;
  int stride = 1;

  for (int i = index; i < size; i += stride) {
    c[i] = addFloat(a[i], b[i]);
  }
}

} // namespace

namespace cpu {

void dispatchKernal(const float *a, const float *b, float *c, int size) {
  kernal(a, b, c, size);
}

} // namespace cpu
