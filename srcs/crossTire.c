#include "cub3d.h"

int crossUp(float *startY, float *ceilY, float *floorY)
{
 printf("Cross Up\n");
 --mstr.mnMp.tmpPos.iy;
 if (isHitWall(mstr.mnMp.tmpPos.ix, mstr.mnMp.tmpPos.iy))
  return (-1);
 *startY -= tireSz;
 *ceilY = *floorY;
 *floorY -= tireSz;
 return (1);
}

int crossDown(float *startY, float *ceilY, float *floorY)
{
 printf("Cross Down => map[%i][%i] is %c\n", mstr.mnMp.tmpPos.iy, mstr.mnMp.tmpPos.ix, mstr.map.map[mstr.mnMp.tmpPos.iy][mstr.mnMp.tmpPos.ix]);
 ++mstr.mnMp.tmpPos.iy;
 if (isHitWall(mstr.mnMp.tmpPos.ix, mstr.mnMp.tmpPos.iy))
  return (-1);
 *startY += tireSz;
 *floorY = *ceilY;
 *ceilY += tireSz;
 return (1);
}

int crossLeft(float *startX, float *ceilX, float *floorX)
{
 printf("Cross Left\n");
 --mstr.mnMp.tmpPos.ix;
 if (isHitWall(mstr.mnMp.tmpPos.ix, mstr.mnMp.tmpPos.iy))
  return (-1);
 *startX -= tireSz;
 *ceilX = *floorX;
 *floorX -= tireSz;
 return (1);
}

int crossRight(float *startX, float *ceilX, float *floorX)
{
 printf("Cross Right => map[%i][%i] is %c\n", mstr.mnMp.tmpPos.iy, mstr.mnMp.tmpPos.ix, mstr.map.map[mstr.mnMp.tmpPos.iy][mstr.mnMp.tmpPos.ix]);
 ++mstr.mnMp.tmpPos.ix;
 if (isHitWall(mstr.mnMp.tmpPos.ix, mstr.mnMp.tmpPos.iy))
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
 mstr.mnMp.tmpPos = (t_point){.ix = x, .iy = y};
 if (mstr.ray.pos.y <= mstr.tire.floor.y &&
     (crossUp(&start.y, &ceil.y, &floor.y) == -1))
  return (-1);
 else if (mstr.ray.pos.y >= mstr.tire.ceil.y &&
          (crossDown(&start.y, &ceil.y, &floor.y) == -1))
  return (-1);
 if (mstr.ray.pos.x <= mstr.tire.floor.x &&
     (crossLeft(&start.x, &ceil.x, &floor.x) == -1))
  return (-1);
 else if (mstr.ray.pos.x >= mstr.tire.ceil.x &&
          (crossRight(&start.x, &ceil.x, &floor.x) == -1))
  return (-1);
 mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
 mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
 mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 mstr.ray.tire = (t_point){.ix = mstr.mnMp.tmpPos.ix, .iy = mstr.mnMp.tmpPos.iy};
 return (1);
}