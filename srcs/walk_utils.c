#include "cub3d.h"

void stepY(int dir, char c)
{
 if (c == 'y')
 {
  mstr.tire.floor.y += (STEP * mstr.ray.dir.y * dir);
  mstr.tire.ceil.y += (STEP * mstr.ray.dir.y * dir);
  mstr.mnMp.start.y += (STEP * mstr.ray.dir.y * dir);
 }
 if (c == 'x')
 {
  mstr.tire.ceil.x += (STEP * mstr.ray.dir.x * dir);
  mstr.tire.floor.x += (STEP * mstr.ray.dir.x * dir);
  mstr.mnMp.start.x += (STEP * mstr.ray.dir.x * dir);
 }
}

void stepX(int dir, char c)
{
 if (c == 'y')
 {
  mstr.tire.floor.y += (STEP * mstr.ray.dir.x * dir);
  mstr.tire.ceil.y += (STEP * mstr.ray.dir.x * dir);
  mstr.mnMp.start.y += (STEP * mstr.ray.dir.x * dir);
 }
 if (c == 'x')
 {
  mstr.tire.ceil.x += (STEP * mstr.ray.dir.y * dir);
  mstr.tire.floor.x += (STEP * mstr.ray.dir.y * dir);
  mstr.mnMp.start.x += (STEP * mstr.ray.dir.y * dir);
 }
}

int isHitWall(int x, int y)
{
 if (input_ok(x, y) && mstr.map.map[y][x] == '1')
 {
  printf("xxxHit wallxxx\n");
  return (1);
 }
 return (0);
}