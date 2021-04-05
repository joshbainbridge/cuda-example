#pragma once

#include "../defines.h"
#include "vector.h"

class Bsdf {
public:
  HOST_DEVICE virtual Vec3f sample(Vec3f n, float u[2]) = 0;
  HOST_DEVICE virtual float f(Vec3f n, Vec3f wi) = 0;
  HOST_DEVICE virtual float pdf(Vec3f n, Vec3f wi) = 0;
};

using BsdfPtr = Bsdf *;

class NullBsdf : public Bsdf {
public:
  HOST_DEVICE NullBsdf() {}
  HOST_DEVICE virtual Vec3f sample(Vec3f n, float u[2]) override;
  HOST_DEVICE virtual float f(Vec3f n, Vec3f wi) override;
  HOST_DEVICE virtual float pdf(Vec3f n, Vec3f wi) override;
};

class DiffuseBsdf : public Bsdf {
public:
  HOST_DEVICE DiffuseBsdf(float albedo) : albedo(albedo) {}
  HOST_DEVICE virtual Vec3f sample(Vec3f n, float u[2]) override;
  HOST_DEVICE virtual float f(Vec3f n, Vec3f wi) override;
  HOST_DEVICE virtual float pdf(Vec3f n, Vec3f wi) override;

private:
  float albedo;
};
