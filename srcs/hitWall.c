#include "cub3d.h"

int hitWallUp(void)
{
 return (mstr.map.map[mstr.ray.tire.iy - 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y <= mstr.tire.floor.iy);
}

int hitWallDown(void)
{
 return (mstr.map.map[mstr.ray.tire.iy + 1][mstr.ray.tire.ix] == '1' && mstr.ray.pos.y >= mstr.tire.ceil.iy);
}

int hitWallLeft(void)
{
 return (mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix - 1] == '1' && mstr.ray.pos.x <= mstr.tire.floor.ix);
}

int hitWallRight(void)
{
 return (mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix + 1] == '1' && mstr.ray.pos.x >= mstr.tire.ceil.ix);
}

int hitWall(char c)
{
 if (c == 'N')
 {
  if (mstr.ray.dir.x < 0 && hitWallLeft())
   return (1);
  if (mstr.ray.dir.x > 0 && hitWallRight())
   return (1);
  return (hitWallUp());
 }
 if (c == 'S')
 {
  if (mstr.ray.dir.x < 0 && hitWallLeft())
   return (1);
  if (mstr.ray.dir.x > 0 && hitWallRight())
   return (1);
  return (hitWallDown());
 }
 if (c == 'E')
 {
  if (mstr.ray.dir.y < 0 && hitWallUp())
   return (1);
  if (mstr.ray.dir.y > 0 && hitWallDown())
   return (1);
  return (hitWallRight());
 }
 if (c == 'W')
 {
  if (mstr.ray.dir.y < 0 && hitWallUp())
   return (1);
  if (mstr.ray.dir.y > 0 && hitWallDown())
   return (1);
  return (hitWallLeft());
 }
 return (0);
}

// int hitWall2(void)
// {
//  if (mstr.ray.dir.y < 0 && hitWallUp())
// }