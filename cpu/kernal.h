#pragma once

#include "../common/vector.h"

namespace cpu {
void dispatchKernal(const Vec3f *n, Vec3f *wi, float *throughput, int size);
}
