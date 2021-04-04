#pragma once

#include "../common/vector.h"

namespace gpu {
void dispatchKernal(const Vec3f *n, Vec3f *wi, float *throughput, int size);
}
