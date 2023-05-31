#include "cub3d.h"

int isOutSide(t_point p)
{
  int isOutSide;

  isOutSide = (p.x < mstr.mnMp.floor.ix || p.x > mstr.mnMp.ceil.ix || p.y < mstr.mnMp.floor.iy || p.y > mstr.mnMp.ceil.iy);
  return (p.x < 0 || p.y < 0 || isOutSide);
}

void lineT(t_point p0, t_point p1)
{
  int step;
  float Xinc;
  float Yinc;

  if (abs(dn(p0.x, p1.x)) > abs(dn(p0.y, p1.y)))
    step = abs(dn(p0.x, p1.x));
  else
    step = abs(dn(p0.y, p1.y));
  Xinc = dn(p0.x, p1.x) / (float)step;
  Yinc = dn(p0.y, p1.y) / (float)step;
  while (step-- >= 0 && !(isOutSide(p0)))
  {
    ft_pixel_put(p0.x, p0.y, mstr.color);
    p0.x += Xinc;
    p0.y += Yinc;
  }
  mstr.ray.lmt.x = p0.x;
  mstr.ray.lmt.y = p0.y;
}

void draw_tire(t_point p, int tireX, int tireY)
{
  lineT(p, (t_point){.x = p.x, .y = p.y + tireSz});
  lineT(p, (t_point){.x = p.x + tireSz, .y = p.y});
  ////////////////////test//////////////////////////
  (void)tireY;
  if (tireX != 0)
    lineT(p, (t_point){.x = p.x - tireSz, .y = p.y});
  //////////////////////////////////////////////////
  p.x += tireSz;
  lineT(p, (t_point){.x = p.x, .y = p.y + tireSz});
  p.y += tireSz;
  lineT(p, (t_point){.x = p.x - tireSz, .y = p.y});
  ////////////////////test//////////////////////////
  if (tireX < (int)ft_strlen(mstr.map.tmp[tireY]) - 2)
    lineT(p, (t_point){.x = p.x + tireSz, .y = p.y});
}

// void draw_wall(int x, int y)
void draw_wall(t_point p)
{
  // line(x, y, x + tireSz, y + tireSz);
  lineT(p, (t_point){.x = p.x + tireSz, p.y + tireSz});
  // line(x + tireSz, y, x, y + tireSz);
  lineT((t_point){.x = p.x + tireSz, .y = p.y}, (t_point){.x = p.x, .y = p.y + tireSz});
}

void re_init_map(void)
{
  int h;
  int w;

  h = -1;
  w = -1;
  while (++h < mstr.map.mapH)
  {
    w = -1;
    while (++w < (int)ft_strlen(mstr.map.map[h]) - 1)
    {
      if (is_keyword(mstr.map.map[h][w]))
        mstr.map.tmp[h][w] = '0';
      else
        mstr.map.tmp[h][w] = mstr.map.map[h][w];
    }
  }
}