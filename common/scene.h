#pragma once

#include "../defines.h"
#include "bsdf.h"

struct Scene {
  HOST_DEVICE Scene();
  HOST_DEVICE ~Scene();

  BsdfPtr bsdfA;
  BsdfPtr bsdfB;
};

HOST_DEVICE void buildScene(Scene *scene);
HOST_DEVICE void destroyScene(Scene *scene);
