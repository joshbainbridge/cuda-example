#pragma once

#include "../defines.h"

struct Vec3f {
  HOST_DEVICE Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
  HOST_DEVICE Vec3f() : x(), y(), z() {}

  float x;
  float y;
  float z;
};
