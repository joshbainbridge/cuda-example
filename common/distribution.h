#pragma once

#include "../defines.h"
#include "vector.h"

HOST_DEVICE void cosineWeightedHemisphere(float u[2], Vec3f &out);
HOST_DEVICE void latitudeLongitudeMapping(float u[2], Vec3f &out);
