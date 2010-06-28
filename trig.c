#include <stdlib.h>
#include <math.h>
#include "trig.h"

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

static float trig_cos_table[] = {
  1.000000, 0.999848, 0.999391, 0.998630, 0.997564, 0.996195,
  0.994522, 0.992546, 0.990268, 0.987688, 0.984808, 0.981627,
  0.978148, 0.974370, 0.970296, 0.965926, 0.961262, 0.956305,
  0.951057, 0.945519, 0.939693, 0.933580, 0.927184, 0.920505,
  0.913545, 0.906308, 0.898794, 0.891007, 0.882948, 0.874620,
  0.866025, 0.857167, 0.848048, 0.838671, 0.829038, 0.819152,
  0.809017, 0.798636, 0.788011, 0.777146, 0.766044, 0.754710,
  0.743145, 0.731354, 0.719340, 0.707107, 0.694658, 0.681998,
  0.669131, 0.656059, 0.642788, 0.629320, 0.615661, 0.601815,
  0.587785, 0.573576, 0.559193, 0.544639, 0.529919, 0.515038,
  0.500000, 0.484810, 0.469472, 0.453990, 0.438371, 0.422618,
  0.406737, 0.390731, 0.374607, 0.358368, 0.342020, 0.325568,
  0.309017, 0.292372, 0.275637, 0.258819, 0.241922, 0.224951,
  0.207912, 0.190809, 0.173648, 0.156434, 0.139173, 0.121869,
  0.104528, 0.087156, 0.069756, 0.052336, 0.034899, 0.017452,
  0.000000,
};

float
trig_cos(int angle)
{
  int   a;
  float ret;

  a = abs(angle) % 180;
  if (a > 90) {
    a = 180 - a;
  }
  ret = trig_cos_table[a];
  a = abs(angle) % 360;
  if ((a > 90) && (a < 270)) {
    ret = -ret;
  }
  return ret;
}

float
trig_sin(int angle)
{
  return trig_cos(90 - angle);
}

float
trig_tan(int angle)
{
  return trig_sin(angle) / trig_cos(angle);
}

int
trig_asin(float x)
{
  return rad2deg(asinf(x));
}

int
trig_acos(float x)
{
  return rad2deg(acosf(x));
}

int
trig_atan2(float y, float x)
{
  return rad2deg(atan2f(y, x));
}


#if 0
#include <stdio.h>

int
main()
{
  int   i, j;
  float f;
  int   t;

  for (i = 0; i < 600; i += 1) {
    printf("%-04d  %-0.6f  %-0.6f\n", i, trig_cos(i), cosf(deg2rad(i)));
  }
  return 0;
}
#endif
