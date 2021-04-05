#include "generate_hit.h"
#include "distribution.h"
#include "random.h"

constexpr int rngSeed = 0;

void generateHit(int index, const Scene &scene, Vec3f &ng) {
  auto state = pcg(pcg(index) + rngSeed);

  float u[2];

  state = pcg(state);
  u[0] = pcgFloat(state);

  state = pcg(state);
  u[1] = pcgFloat(state);

  Vec3f normal;
  latitudeLongitudeMapping(u, normal);

  ng = normal;
}
