#pragma once

#include "../defines.h"
#include "hit.h"
#include "scene.h"

HOST_DEVICE void generateHit(int index, const Scene &scene, Hit &hit);
