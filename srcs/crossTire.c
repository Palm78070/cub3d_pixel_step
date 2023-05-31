#include "cub3d.h"

int crossUp(int y, float *startY, float *ceilY, float *floorY)
{
 if (isHitWall(mstr.ray.tire.ix, y))
  return (-1);
 *startY -= tireSz;
 *ceilY = *floorY;
 *floorY -= tireSz;
 return (1);
}

int crossDown(int y, float *startY, float *ceilY, float *floorY)
{
 if (isHitWall(mstr.ray.tire.ix, y))
  return (-1);
 *startY += tireSz;
 *floorY = *ceilY;
 *ceilY += tireSz;
 return (1);
}

int crossLeft(int x, float *startX, float *ceilX, float *floorX)
{
 if (isHitWall(x, mstr.ray.tire.iy))
  return (-1);
 *startX -= tireSz;
 *ceilX = *floorX;
 *floorX -= tireSz;
 return (1);
}

int crossRight(int x, float *startX, float *ceilX, float *floorX)
{
 if (isHitWall(x, mstr.ray.tire.iy))
  return (-1);
 *startX += tireSz;
 *floorX = *ceilX;
 *ceilX += tireSz;
 return (1);
}

int crossTire(int x, int y)
{
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.x = mstr.mnMp.start.x, .y = mstr.mnMp.start.y};
 ceil = (t_point){.x = mstr.tire.ceil.x, .y = mstr.tire.ceil.y};
 floor = (t_point){.x = mstr.tire.floor.x, .y = mstr.tire.floor.y};
 if (mstr.ray.pos.y <= mstr.tire.floor.y &&
     (crossUp(--y, &start.y, &ceil.y, &floor.y) == -1))
  return (-1);
 else if (mstr.ray.pos.y >= mstr.tire.ceil.y &&
          (crossDown(++y, &start.y, &ceil.y, &floor.y) == -1))
  return (-1);
 if (mstr.ray.pos.x <= mstr.tire.floor.x &&
     (crossLeft(--x, &start.x, &ceil.x, &floor.x) == -1))
  return (-1);
 else if (mstr.ray.pos.x >= mstr.tire.ceil.x &&
          (crossRight(++x, &start.x, &ceil.x, &floor.x) == -1))
  return (-1);
 mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
 mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
 mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 mstr.ray.tire = (t_point){.ix = x, .iy = y};
 return (1);
}