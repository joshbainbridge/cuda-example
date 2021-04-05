#include "ray_sample.h"
#include "random.h"

constexpr int rngSeed = 1;

void raySample(int index, Vec3f n, BsdfPtr bsdf, Vec3f &wi, float &f) {
  auto state = pcg(pcg(index) + rngSeed);

  float u[2];

  state = pcg(state);
  u[0] = pcgFloat(state);

  state = pcg(state);
  u[1] = pcgFloat(state);

  wi = bsdf->sample(n, u);

  float eval = bsdf->f(n, wi);
  float pdf = bsdf->pdf(n, wi);

  if (pdf == 0.0f) {
    f = 0.0f;
    return;
  }

  f = eval / pdf;
}
