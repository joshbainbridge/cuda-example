#include "generate_hit.h"
#include "distribution.h"
#include "random.h"

constexpr int rngSeed = 0;

void generateHit(int index, const Scene &scene, Vec3f &ng, BsdfPtr &bsdf) {
  auto state = pcg(pcg(index) + rngSeed);

  float u[3];

  state = pcg(state);
  u[0] = pcgFloat(state);

  state = pcg(state);
  u[1] = pcgFloat(state);

  state = pcg(state);
  u[2] = pcgFloat(state);

  Vec3f normal;
  latitudeLongitudeMapping(u, normal);

  BsdfPtr shader;
  if (u[2] < 0.5f) {
    shader = scene.bsdfA;
  } else {
    shader = scene.bsdfB;
  }

  ng = normal;
  bsdf = shader;
}
