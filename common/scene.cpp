#include "scene.h"

#include <new>

Scene::Scene() {
  bsdfA = new NullBsdf();
  bsdfB = new DiffuseBsdf(1.0f);
}

Scene::~Scene() {
  delete bsdfA;
  delete bsdfB;
}

void buildScene(Scene *scene) { new (scene) Scene(); }
void destroyScene(Scene *scene) { scene->~Scene(); }
