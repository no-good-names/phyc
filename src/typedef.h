#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdint.h>

typedef struct Point_t {
  uint32_t x;
  uint32_t y;
} Point;

typedef struct v2_t {
  Point P1;
  Point P2;
} v2;

#endif // !TYPEDEF_H
