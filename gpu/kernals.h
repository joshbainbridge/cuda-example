#pragma once

#include "../common/hit.h"
#include "../common/scene.h"
#include "../common/vector.h"

namespace gpu {
void buildScene(Scene *scene);
void destroyScene(Scene *scene);
void generateHits(const Scene *scene, Hit *hit, int size);
void sampleRays(const Hit *hit, Vec3f *wi, float *f, int size);
} // namespace gpu
