#include "bsdf.h"
#include "distribution.h"

#include <math.h>

namespace {

HOST_DEVICE float dot(Vec3f a, Vec3f b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

HOST_DEVICE Vec3f add(Vec3f a, Vec3f b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

HOST_DEVICE Vec3f mult(Vec3f a, float b) { return {a.x * b, a.y * b, a.z * b}; }

HOST_DEVICE Vec3f outBasis(Vec3f n, Vec3f b1, Vec3f b2, Vec3f out) {
  return add(mult(b1, out.x), add(mult(b2, out.y), mult(n, out.z)));
}

HOST_DEVICE void branchlessONB(Vec3f n, Vec3f &b1, Vec3f &b2) {
  float sign = copysignf(1.0f, n.z);
  const float a = -1.0f / (sign + n.z);
  const float b = n.x * n.y * a;
  b1 = Vec3f(1.0f + sign * n.x * n.x * a, sign * b, -sign * n.x);
  b2 = Vec3f(b, sign + n.y * n.y * a, -n.y);
}

} // namespace

Vec3f DiffuseBsdf::sample(Vec3f n, float u[2]) {
  Vec3f b1, b2;
  branchlessONB(n, b1, b2);

  Vec3f wi;
  cosineWeightedHemisphere(u, wi);

  return outBasis(n, b1, b2, wi);
}

float DiffuseBsdf::f(Vec3f n, Vec3f wi) {
  return fmax(albedo * dot(n, wi) / M_PI, 0.0);
}

float DiffuseBsdf::pdf(Vec3f n, Vec3f wi) {
  return fmax(dot(n, wi) / M_PI, 0.0);
}
