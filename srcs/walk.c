#include "cub3d.h"

void ft_walkUp(void)
{
 // if (mstr.ray.pos.y <= mstr.tire.floor.iy)
 // {
 //  mstr.ray.tire.iy -= 1;
 //  mstr.mnMp.start.iy -= tireSz;
 //  mstr.tire.ceil.iy = mstr.tire.floor.iy;
 //  mstr.tire.floor.iy -= tireSz;
 // }
 // if (mstr.map.map[mstr.ray.tire.iy - 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y <= mstr.tire.floor.iy)
 if (mstr.ray.dir.y > 0 && hitWall('S'))
 {
  printf("Hit Wall on Down!!!!\n");
  return;
 }
 else if (hitWall('N'))
 {
  printf("Hit Wall on Up!!!!\n");
  return;
 }
 if (mstr.ray.dir.y > 0 && crossTire('S'))
 {
  printf("!!!!player is face down!!!!\n");
 }
 else if (crossTire('N'))
 {
 }
 else
 {
  printf("In stepUp\n");
  // mstr.tire.floor.iy += STEP;
  // mstr.tire.ceil.iy += STEP;
  // mstr.mnMp.start.iy += STEP;

  // if (mstr.ray.dir.y > 0)
  //  if (mstr.ray.dir.y + 0.01 >= 1)
  //   mstr.ray.dir.y = 1;
  // if (mstr.ray.dir.x > 0 && mstr.ray.dir.x < 0.1)
  //  mstr.ray.dir.x = 0;
  mstr.tire.floor.iy -= (STEP * mstr.ray.dir.y);
  mstr.tire.floor.ix -= (STEP * mstr.ray.dir.x);
  mstr.tire.ceil.iy -= (STEP * mstr.ray.dir.y);
  mstr.tire.ceil.ix -= (STEP * mstr.ray.dir.x);
  mstr.mnMp.start.iy -= (STEP * mstr.ray.dir.y);
  mstr.mnMp.start.ix -= (STEP * mstr.ray.dir.x);
 }
 re_draw();
}

void ft_walkDown(void)
{
 // if (mstr.ray.pos.y >= mstr.tire.ceil.iy)
 // {
 //  mstr.ray.tire.iy += 1;
 //  mstr.mnMp.start.iy += tireSz;
 //  mstr.tire.floor.iy = mstr.tire.ceil.iy;
 //  mstr.tire.ceil.iy += tireSz;
 // }
 // if (mstr.map.map[mstr.ray.tire.iy + 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y >= mstr.tire.ceil.iy)
 if (hitWall('S'))
 {
  printf("Hit Wall on Down!!!!\n");
  return;
 }
 if (!crossTire('S'))
 {
  printf("In stepDown\n");
  // mstr.tire.ceil.iy -= STEP;
  // mstr.tire.floor.iy -= STEP;
  // mstr.mnMp.start.iy -= STEP;
  if (mstr.ray.dir.x > 0 && mstr.ray.dir.x < 0.1)
   mstr.ray.dir.x = 0;
  mstr.tire.floor.iy += (STEP * mstr.ray.dir.y);
  mstr.tire.floor.ix += (STEP * mstr.ray.dir.x);
  mstr.tire.ceil.iy += (STEP * mstr.ray.dir.y);
  mstr.tire.ceil.ix += (STEP * mstr.ray.dir.x);
  mstr.mnMp.start.iy += (STEP * mstr.ray.dir.y);
  mstr.mnMp.start.ix += (STEP * mstr.ray.dir.x);
 }
 re_draw();
}

void ft_walkLeft(void)
{
 // if ((mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix - 1] == '1' && mstr.ray.pos.x <= mstr.tire.floor.ix))
 if (hitWall('W'))
 {
  printf("Hit Wall on Left!!!!\n");
  return;
 }
 if (!crossTire('W'))
 {
  printf("In stepLeft\n");

  // mstr.tire.floor.iy -= (STEP * mstr.ray.dir.y);
  // mstr.tire.floor.ix -= (STEP * mstr.ray.dir.x);
  // mstr.tire.ceil.iy -= (STEP * mstr.ray.dir.y);
  // mstr.tire.ceil.ix -= (STEP * mstr.ray.dir.x);
  // mstr.mnMp.start.iy -= (STEP * mstr.ray.dir.y);
  // mstr.mnMp.start.ix -= (STEP * mstr.ray.dir.x);
  if (mstr.ray.dir.x > 0 && mstr.ray.dir.x < 0.1)
   mstr.ray.dir.x = 0;
  if (mstr.ray.dir.x == 0)
  {
   printf("x is 0\n");
   mstr.tire.floor.ix += STEP;
   mstr.tire.ceil.ix += STEP;
   mstr.mnMp.start.ix += STEP;
  }
  else
  {
   mstr.tire.floor.iy -= (STEP * mstr.ray.dir.y);
   printf("Before floorX %i\n", mstr.tire.floor.ix);
   mstr.tire.floor.ix += (STEP * mstr.ray.dir.x);
   printf("After floorX %i\n", mstr.tire.floor.ix);
   mstr.tire.ceil.iy -= (STEP * mstr.ray.dir.y);
   mstr.tire.ceil.ix += (STEP * mstr.ray.dir.x);
   mstr.mnMp.start.iy -= (STEP * mstr.ray.dir.y);
   mstr.mnMp.start.ix += (STEP * mstr.ray.dir.x);
  }
  // printf("Test int float floorX -= (STEP * dirX) => %f\n", mstr.tire.floor.ix - (STEP * mstr.ray.dir.x));
 }
 re_draw();
}

void ft_walkRight(void)
{
 // if ((mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix + 1] == '1' && mstr.ray.pos.x >= mstr.tire.ceil.ix))
 printf("Walk right\n");
 if (hitWall('E'))
 {
  printf("Hit Wall on Right!!!!\n");
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