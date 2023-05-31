#include "cub3d.h"

void walkUp(int x, int y)
{
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.x = mstr.mnMp.start.x, .y = mstr.mnMp.start.y};
 ceil = (t_point){.x = mstr.tire.ceil.x, .y = mstr.tire.ceil.y};
 floor = (t_point){.x = mstr.tire.floor.x, .y = mstr.tire.floor.y};
 if (mstr.ray.dir.y >= -1 && mstr.ray.dir.y < 0)
  stepY(-1, 'y');
 else if (mstr.ray.dir.y > 0 && mstr.ray.dir.y <= 1)
  stepY(-1, 'y');
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x < 0)
  stepY(-1, 'x');
 else if (mstr.ray.dir.x > 0 && mstr.ray.dir.x <= 1)
  stepY(-1, 'x');
 if (crossTire(x, y) == -1)
 {
  mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
  mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
  mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 }
 re_draw();
}

void walkDown(int x, int y)
{
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.x = mstr.mnMp.start.x, .y = mstr.mnMp.start.y};
 ceil = (t_point){.x = mstr.tire.ceil.x, .y = mstr.tire.ceil.y};
 floor = (t_point){.x = mstr.tire.floor.x, .y = mstr.tire.floor.y};
 if (mstr.ray.dir.y >= -1 && mstr.ray.dir.y < 0)
  stepY(1, 'y');
 else if (mstr.ray.dir.y > 0 && mstr.ray.dir.y <= 1)
  stepY(1, 'y');
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x < 0)
  stepY(1, 'x');
 else if (mstr.ray.dir.x > 0 && mstr.ray.dir.x <= 1)
  stepY(1, 'x');
 if (crossTire(x, y) == -1)
 {
  mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
  mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
  mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 }
 re_draw();
}

void walkLeft(int x, int y)
{
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.x = mstr.mnMp.start.x, .y = mstr.mnMp.start.y};
 ceil = (t_point){.x = mstr.tire.ceil.x, .y = mstr.tire.ceil.y};
 floor = (t_point){.x = mstr.tire.floor.x, .y = mstr.tire.floor.y};
 if (mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= 0)
  stepX(1, 'y');
 else if (mstr.ray.dir.y >= 0 && mstr.ray.dir.y <= 1)
  stepX(1, 'y');
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= 0)
  stepX(-1, 'x');
 else if (mstr.ray.dir.x > 0 && mstr.ray.dir.x <= 1)
  stepX(-1, 'x');
 if (crossTire(x, y) == -1)
 {
  mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
  mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
  mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 }
 re_draw();
}

void walkRight(int x, int y)
{
 t_point start;
 t_point ceil;
 t_point floor;

 start = (t_point){.x = mstr.mnMp.start.x, .y = mstr.mnMp.start.y};
 ceil = (t_point){.x = mstr.tire.ceil.x, .y = mstr.tire.ceil.y};
 floor = (t_point){.x = mstr.tire.floor.x, .y = mstr.tire.floor.y};
 if (mstr.ray.dir.y >= -1 && mstr.ray.dir.y <= 0)
  stepX(-1, 'y');
 else if (mstr.ray.dir.y >= 0 && mstr.ray.dir.y <= 1)
  stepX(-1, 'y');
 if (mstr.ray.dir.x >= -1 && mstr.ray.dir.x <= 0)
  stepX(1, 'x');
 else if (mstr.ray.dir.x > 0 && mstr.ray.dir.x <= 1)
  stepX(1, 'x');
 if (crossTire(x, y) == -1)
 {
  mstr.mnMp.start = (t_point){.x = start.x, .y = start.y};
  mstr.tire.floor = (t_point){.x = floor.x, .y = floor.y};
  mstr.tire.ceil = (t_point){.x = ceil.x, .y = ceil.y};
 }
 re_draw();
}