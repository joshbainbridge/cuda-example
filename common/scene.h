#pragma once

#include "../defines.h"

struct Scene {
  HOST_DEVICE Scene() : bsdfA(), bsdfB() {}

  void *bsdfA;
  void *bsdfB;
};
