#pragma once

#include "../common/bsdf.h"
#include "../common/scene.h"
#include "../common/vector.h"

namespace cpu {
void buildScene(Scene *scene);
void destroyScene(Scene *scene);
void generateHits(const Scene *scene, Vec3f *ng, BsdfPtr *bsdf, int size);
void sampleRays(const Vec3f *ng, const BsdfPtr *bsdf, Vec3f *wi, float *f,
                int size);
} // namespace cpu
