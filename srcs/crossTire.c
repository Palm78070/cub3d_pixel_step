#include "cub3d.h"

int crossUp(void)
{
 if (mstr.ray.pos.y <= mstr.tire.floor.iy)
 {
  printf("Cross Up!!!\n");
  mstr.ray.tire.iy -= 1;
  mstr.mnMp.start.iy -= tireSz;
  mstr.tire.ceil.iy = mstr.tire.floor.iy;
  mstr.tire.floor.iy -= tireSz;
  return (1);
 }
 return (0);
}

int crossDown(void)
{
 if (mstr.ray.pos.y >= mstr.tire.ceil.iy)
 {
  printf("Cross Down!!!\n");
  mstr.ray.tire.iy += 1;
  mstr.mnMp.start.iy += tireSz;
  mstr.tire.floor.iy = mstr.tire.ceil.iy;
  mstr.tire.ceil.iy += tireSz;
  return (1);
 }
 return (0);
}

int crossLeft(void)
{
 if (mstr.ray.pos.x <= mstr.tire.floor.ix)
 {
  printf("Cross Left!!!\n");
  mstr.ray.tire.ix -= 1;
  mstr.mnMp.start.ix -= tireSz;
  mstr.tire.ceil.ix = mstr.tire.floor.ix;
  mstr.tire.floor.ix -= tireSz;
  return (1);
 }
 return (0);
}

int crossRight(void)
{
 if (mstr.ray.pos.x >= mstr.tire.ceil.ix)
 {
  printf("Cross Right!!!\n");
  mstr.ray.tire.ix += 1;
  mstr.mnMp.start.ix += tireSz;
  mstr.tire.floor.ix = mstr.tire.ceil.ix;
  mstr.tire.ceil.ix += tireSz;
  return (1);
 }
 return (0);
}

int crossTire(char c)
{
 if (c == 'N')
 {
  if (mstr.ray.dir.x < 0)
   crossLeft();
  if (mstr.ray.dir.x > 0)
   crossRight();
  return (crossUp());
 }
 else if (c == 'S')
 {
  if (mstr.ray.dir.x < 0)
   crossLeft();
  if (mstr.ray.dir.x > 0)
   crossRight();
  return (crossDown());
 }
 else if (c == 'W')
 {
  if (mstr.ray.dir.y < 0)
   crossUp();
  if (mstr.ray.dir.y > 0)
   crossDown();
  return (crossLeft());
 }
 else if (c == 'E')
 {
  if (mstr.ray.dir.y < 0)
   crossUp();
  if (mstr.ray.dir.y > 0)
   crossDown();
  return (crossRight());
 }
 return (0);
}