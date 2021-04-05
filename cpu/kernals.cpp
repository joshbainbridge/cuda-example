#include "kernals.h"

#include "../common/generate_hit.h"
#include "../common/ray_sample.h"

namespace {
namespace kernals {

void buildScene(Scene *scene) { ::buildScene(scene); }

void destroyScene(Scene *scene) { ::destroyScene(scene); }

void generateHits(const Scene *scene, Hit *hit, int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    generateHit(i, *scene, hit[i]);
  }
}

void sampleRays(const Hit *hit, Vec3f *wi, float *f, int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    raySample(i, hit[i], wi[i], f[i]);
  }
}

} // namespace kernals
} // namespace

namespace cpu {

void buildScene(Scene *scene) { kernals::buildScene(scene); }

void destroyScene(Scene *scene) { kernals::destroyScene(scene); }

void generateHits(const Scene *scene, Hit *hit, int size) {
  kernals::generateHits(scene, hit, size);
}

void sampleRays(const Hit *hit, Vec3f *wi, float *f, int size) {
  kernals::sampleRays(hit, wi, f, size);
}

} // namespace cpu
