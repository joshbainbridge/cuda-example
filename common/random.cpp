#include "random.h"

uint32_t pcg(uint32_t v) {
  uint32_t state = v * 747796405u + 2891336453u;
  uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
  return (word >> 22u) ^ word;
}

float pcgFloat(uint32_t v) { return v * 0x1p-32f; }
