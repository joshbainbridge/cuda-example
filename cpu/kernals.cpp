#include "kernals.h"

#include "../common/build_scene.h"
#include "../common/generate_hit.h"
#include "../common/ray_sample.h"

namespace {
namespace kernals {

void buildScene(Scene *scene) { ::buildScene(scene); }

void generateHits(const Scene *scene, Vec3f *ng, int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    generateHit(i, *scene, ng[i]);
  }
}

void sampleRays(const Vec3f *ng, Vec3f *wi, float *f, int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    raySample(i, ng[i], wi[i], f[i]);
  }
}

} // namespace kernals
} // namespace

namespace cpu {

void buildScene(Scene *scene) { kernals::buildScene(scene); }

void generateHits(const Scene *scene, Vec3f *ng, int size) {
  kernals::generateHits(scene, ng, size);
}

void sampleRays(const Vec3f *ng, Vec3f *wi, float *f, int size) {
  kernals::sampleRays(ng, wi, f, size);
}

} // namespace cpu
