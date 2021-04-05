#pragma once

#include "../common/scene.h"
#include "../common/vector.h"

namespace gpu {
void buildScene(Scene *scene);
void generateHits(const Scene *scene, Vec3f *ng, int size);
void sampleRays(const Vec3f *ng, Vec3f *wi, float *f, int size);
} // namespace gpu
