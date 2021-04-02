#include "kernal.h"

#include "../common/add_float.h"

namespace {

void dispatch(const float *argA, const float *argB, float *argC, int index) {
  int tid = index;

  argC[tid] = addFloat(argA[tid], argB[tid]);
}

} // namespace

namespace cpu {

void kernal(const float *argA, const float *argB, float *argC, int size) {
  for (int i = 0; i < size; ++i) {
    dispatch(argA, argB, argC, i);
  }
}

} // namespace cpu
