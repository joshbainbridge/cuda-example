#include "ray_sample.h"
#include "bsdf.h"
#include "random.h"

constexpr int rngSeed = 1;

void raySample(int index, Vec3f n, Vec3f &wi, float &throughput) {
  auto state = pcg(pcg(index) + rngSeed);

  float u[2];

  state = pcg(state);
  u[0] = pcgFloat(state);

  state = pcg(state);
  u[1] = pcgFloat(state);

  DiffuseBsdf bsdf(0.5f);
  wi = bsdf.sample(n, u);

  float f = bsdf.f(n, wi);
  float pdf = bsdf.pdf(n, wi);

  if (pdf == 0.0f) {
    throughput = 0.0f;
    return;
  }

  throughput = f / pdf;
}
