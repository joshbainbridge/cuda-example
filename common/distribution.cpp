#include "distribution.h"

#include <math.h>

void cosineWeightedHemisphere(float u[2], Vec3f &out) {
  out.x = sqrt(u[0]) * cos(2 * M_PI * u[1]);
  out.y = sqrt(u[0]) * sin(2 * M_PI * u[1]);
  out.z = sqrt(1 - u[0]);
}

void latitudeLongitudeMapping(float u[2], Vec3f &out) {
  float a = 1 - 2 * u[0];
  float b = sqrt(1 - a * a);
  float phi = 2 * M_PI * u[1];
  out.x = b * cos(phi);
  out.y = b * sin(phi);
  out.z = a;
}
