#pragma once

#include "../defines.h"
#include "vector.h"

class DiffuseBsdf {
public:
  HOST_DEVICE DiffuseBsdf(float albedo) : albedo(albedo) {}

  HOST_DEVICE Vec3f sample(Vec3f n, float u[2]);
  HOST_DEVICE float f(Vec3f n, Vec3f wi);
  HOST_DEVICE float pdf(Vec3f n, Vec3f wi);

private:
  float albedo;
};
