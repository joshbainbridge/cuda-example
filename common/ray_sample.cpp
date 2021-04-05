#include "ray_sample.h"
#include "random.h"

constexpr int rngSeed = 1;

void raySample(int index, const Hit &hit, Vec3f &wi, float &f) {
  auto state = pcg(pcg(index) + rngSeed);

  float u[2];

  state = pcg(state);
  u[0] = pcgFloat(state);

  state = pcg(state);
  u[1] = pcgFloat(state);

  wi = hit.bsdf->sample(hit.ng, u);

  float eval = hit.bsdf->f(hit.ng, wi);
  float pdf = hit.bsdf->pdf(hit.ng, wi);

  if (pdf == 0.0f) {
    f = 0.0f;
    return;
  }

  f = eval / pdf;
}
