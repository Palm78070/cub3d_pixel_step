#include "cub3d.h"

int crossTire(int x, int y)
{
 printf("In crossTire\n");
 printf("x: %i y: %i\n", x, y);
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.ix = mstr.mnMp.start.ix, .iy = mstr.mnMp.start.iy};
 ceil = (t_point){.ix = mstr.tire.ceil.ix, .iy = mstr.tire.ceil.iy};
 floor = (t_point){.ix = mstr.tire.floor.ix, .iy = mstr.tire.floor.iy};
 if (mstr.ray.pos.y <= mstr.tire.floor.iy)
 {
  printf("??????Cross Up???????\n");
  y -= 1;
  start.iy -= tireSz;
  ceil.iy = mstr.tire.floor.iy;
  floor.iy -= tireSz;
 }
 else if (mstr.ray.pos.y >= mstr.tire.ceil.iy)
 {
  printf("??????Cross Down???????\n");
  y += 1;
  start.iy += tireSz;
  floor.iy = mstr.tire.ceil.iy;
  ceil.iy += tireSz;
 }
 if (mstr.ray.pos.x <= mstr.tire.floor.ix)
 {
  printf("??????Cross Left???????\n");
  x -= 1;
  start.ix -= tireSz;
  ceil.ix = mstr.tire.floor.ix;
  floor.ix -= tireSz;
 }
 else if (mstr.ray.pos.x >= mstr.tire.ceil.ix)
 {
  printf("??????Cross Right???????\n");
  x += 1;
  start.ix += tireSz;
  floor.ix = mstr.tire.ceil.ix;
  ceil.ix += tireSz;
 }
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
 {
  printf("xxxHit wallxxx\n");
  return (-1);
 }
 mstr.mnMp.start = (t_point){.ix = start.ix, .iy = start.iy};
 mstr.tire.floor = (t_point){.ix = floor.ix, .iy = floor.iy};
 mstr.tire.ceil = (t_point){.ix = ceil.ix, .iy = ceil.iy};
 mstr.ray.tire = (t_point){.ix = x, .iy = y};
 return (1);
}

// int crossUp(void)
// {
//  if (mstr.ray.pos.y <= mstr.tire.floor.iy)
//  {
//   printf("Cross Up!!!\n");
//   mstr.ray.tire.iy -= 1;
//   mstr.mnMp.start.iy -= tireSz;
//   mstr.tire.ceil.iy = mstr.tire.floor.iy;
//   mstr.tire.floor.iy -= tireSz;
//   return (1);
//  }
//  return (0);
// }

// int crossDown(void)
// {
//  if (mstr.ray.pos.y >= mstr.tire.ceil.iy)
//  {
//   printf("Cross Down!!!\n");
//   mstr.ray.tire.iy += 1;
//   mstr.mnMp.start.iy += tireSz;
//   mstr.tire.floor.iy = mstr.tire.ceil.iy;
//   mstr.tire.ceil.iy += tireSz;
//   return (1);
//  }
//  return (0);
// }

// int crossLeft(void)
// {
//  if (mstr.ray.pos.x <= mstr.tire.floor.ix)
//  {
//   printf("Cross Left!!!\n");
//   mstr.ray.tire.ix -= 1;
//   mstr.mnMp.start.ix -= tireSz;
//   mstr.tire.ceil.ix = mstr.tire.floor.ix;
//   mstr.tire.floor.ix -= tireSz;
//   return (1);
//  }
//  return (0);
// }

// int crossRight(void)
// {
//  if (mstr.ray.pos.x >= mstr.tire.ceil.ix)
//  {
//   printf("Cross Right!!!\n");
//   mstr.ray.tire.ix += 1;
//   mstr.mnMp.start.ix += tireSz;
//   mstr.tire.floor.ix = mstr.tire.ceil.ix;
//   mstr.tire.ceil.ix += tireSz;
//   return (1);
//  }
//  return (0);
// }

// int crossTire(char c)
// {
//  if (c == 'N')
//  {
//   if (mstr.ray.dir.x < 0)
//    crossLeft();
//   if (mstr.ray.dir.x > 0)
//    crossRight();
//   return (crossUp());
//  }
//  else if (c == 'S')
//  {
//   if (mstr.ray.dir.x < 0)
//    crossLeft();
//   if (mstr.ray.dir.x > 0)
//    crossRight();
//   return (crossDown());
//  }
//  else if (c == 'W')
//  {
//   if (mstr.ray.dir.y < 0)
//    crossUp();
//   if (mstr.ray.dir.y > 0)
//    crossDown();
//   return (crossLeft());
//  }
//  else if (c == 'E')
//  {
//   if (mstr.ray.dir.y < 0)
//    crossUp();
//   if (mstr.ray.dir.y > 0)
//    crossDown();
//   return (crossRight());
//  }
//  return (0);
// }