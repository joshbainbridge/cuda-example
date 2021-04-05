#pragma once

#include "bsdf.h"
#include "vector.h"

struct Hit {
  Vec3f ng;
  BsdfPtr bsdf;
};
