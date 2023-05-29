#include "cub3d.h"

float lmtDir(float n)
{
 if (n > 1)
  n = 1;
 if (n < -1)
  n = -1;
 return (n);
}

float ft_roundf2(float n)
{
 return (roundf(n * 10) / 10);
}