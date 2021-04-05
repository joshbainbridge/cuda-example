#include "kernals.h"

#include "../common/generate_hit.h"
#include "../common/ray_sample.h"

namespace {
namespace kernals {

void buildScene(Scene *scene) { ::buildScene(scene); }

void destroyScene(Scene *scene) { ::destroyScene(scene); }

void generateHits(const Scene *scene, Vec3f *ng, BsdfPtr *bsdf, int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    generateHit(i, *scene, ng[i], bsdf[i]);
  }
}

void sampleRays(const Vec3f *ng, const BsdfPtr *bsdf, Vec3f *wi, float *f,
                int size) {
  const int index = 0;
  const int stride = 1;

  for (int i = index; i < size; i += stride) {
    raySample(i, ng[i], bsdf[i], wi[i], f[i]);
  }
}

} // namespace kernals
} // namespace

namespace cpu {

void buildScene(Scene *scene) { kernals::buildScene(scene); }

void destroyScene(Scene *scene) { kernals::destroyScene(scene); }

void generateHits(const Scene *scene, Vec3f *ng, BsdfPtr *bsdf, int size) {
  kernals::generateHits(scene, ng, bsdf, size);
}

void sampleRays(const Vec3f *ng, const BsdfPtr *bsdf, Vec3f *wi, float *f,
                int size) {
  kernals::sampleRays(ng, bsdf, wi, f, size);
}

} // namespace cpu
