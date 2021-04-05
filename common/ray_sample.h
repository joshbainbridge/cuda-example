#pragma once

#include "../defines.h"
#include "hit.h"
#include "vector.h"

HOST_DEVICE void raySample(int index, const Hit &hit, Vec3f &wi, float &f);
