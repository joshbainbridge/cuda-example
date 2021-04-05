#pragma once

#include "../defines.h"
#include "scene.h"
#include "vector.h"

HOST_DEVICE void generateHit(int index, const Scene &scene, Vec3f &ng);
