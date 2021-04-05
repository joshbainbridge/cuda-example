#pragma once

#include "../defines.h"
#include "bsdf.h"
#include "vector.h"

HOST_DEVICE void raySample(int index, Vec3f n, BsdfPtr bsdf, Vec3f &wi,
                           float &f);
