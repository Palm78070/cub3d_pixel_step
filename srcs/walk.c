#include "cub3d.h"

void ft_walkUp(void)
{
 if (mstr.map.map[mstr.ray.tire.iy - 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y <= mstr.tire.floor.iy)
  return;
 if (mstr.ray.pos.y <= mstr.tire.floor.iy)
 {
  mstr.ray.tire.iy -= 1;
  mstr.mnMp.start.iy -= tireSz;
  mstr.tire.ceil.iy = mstr.tire.floor.iy;
  mstr.tire.floor.iy -= tireSz;
 }
 else
 {
  mstr.tire.floor.iy += STEP;
  mstr.tire.ceil.iy += STEP;
  mstr.mnMp.start.iy += STEP;
 }
 re_draw();
}

void ft_walkDown(void)
{
 if (mstr.map.map[mstr.ray.tire.iy + 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y >= mstr.tire.ceil.iy)
 {
  printf("Bug Down!!!!\n");
  return;
 }
 if (mstr.ray.pos.y >= mstr.tire.ceil.iy)
 {
  mstr.ray.tire.iy += 1;
  mstr.mnMp.start.iy += tireSz;
  mstr.tire.floor.iy = mstr.tire.ceil.iy;
  mstr.tire.ceil.iy += tireSz;
 }
 else
 {
  mstr.tire.ceil.iy -= STEP;
  mstr.tire.floor.iy -= STEP;
  mstr.mnMp.start.iy -= STEP;
 }
 re_draw();
}

void ft_walkLeft(void)
{
 if ((mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix - 1] == '1' && mstr.ray.pos.x <= mstr.tire.floor.ix))
 {
  printf("Bug Left!!!!\n");
  return;
 }
 if (mstr.ray.pos.x <= mstr.tire.floor.ix)
 {
  mstr.ray.tire.ix -= 1;
  mstr.mnMp.start.ix -= tireSz;
  mstr.tire.ceil.ix = mstr.tire.floor.ix;
  mstr.tire.floor.ix -= tireSz;
 }
 else
 {
  mstr.tire.floor.ix += STEP;
  mstr.tire.ceil.ix += STEP;
  mstr.mnMp.start.ix += STEP;
 }
 re_draw();
}

void ft_walkRight(void)
{
 if ((mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix + 1] == '1' && mstr.ray.pos.x >= mstr.tire.ceil.ix))
 {
  printf("Bug Right!!!!\n");
  return;
 }
 if (mstr.ray.pos.x >= mstr.tire.ceil.ix)
 {
  mstr.ray.tire.ix += 1;
  mstr.mnMp.start.ix += tireSz;
  mstr.tire.floor.ix = mstr.tire.ceil.ix;
  mstr.tire.ceil.ix += tireSz;
 }
 else
 {
  mstr.tire.ceil.ix -= STEP;
  mstr.tire.floor.ix -= STEP;
  mstr.mnMp.start.ix -= STEP;
 }
 re_draw();
}