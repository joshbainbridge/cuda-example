#pragma once

#include "../defines.h"
#include "bsdf.h"

HOST_DEVICE void raySample(int index, Vec3f n, Vec3f &wi, float &throughput);
