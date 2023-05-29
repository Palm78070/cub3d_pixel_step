#include "cub3d.h"

t_vec rotate(t_vec v)
{
  // printf("Before Rotate v.x: %f v.y: %f\n", v.x, v.y);
  float old_x;

  old_x = v.x;
  v.x = (v.x * cosf(mstr.rot.rad)) - (v.y * sinf(mstr.rot.rad));
  v.y = ((old_x * sinf(mstr.rot.rad)) + (v.y * cosf(mstr.rot.rad)));
  // if (v.y > 1)
  //   v.y = 1;
  // if (v.y < -1)
  //   v.y = -1;
  // if (v.x > 1)
  //   v.x = 1;
  // if (v.x < -1)
  //   v.x = -1;
  v.y = lmtDir(v.y);
  v.x = lmtDir(v.x);
  // v.x = roundf(v.x * 10) / 10;
  // v.y = roundf(v.y * 10) / 10;
  v.x = ft_roundf2(v.x);
  v.y = ft_roundf2(v.y);
  // printf("After Rotate v.x: %f v.y: %f\n", v.x, v.y);
  return (v);
}

void drawRay(void)
{
  float posY;
  float posX;
  float dstX;
  float dstY;

  posY = mstr.ray.pos.y;
  posX = mstr.ray.pos.x;
  dstX = (posX + (mstr.ray.dir.x * tireSz));
  dstY = (posY + (mstr.ray.dir.y * tireSz));
  if (mstr.ray.camX == 0)
  {
    mstr.color = 0x90EE90;
    line(posX, posY, dstX, dstY);
    mstr.color = 0xFFFFFF;
  }
}

void percentTire(void)
{
  mstr.ray.pcnt = (t_point){.x = (mstr.ray.pos.x - mstr.tire.floor.ix) / tireSz,
                            .y = (mstr.ray.pos.y - mstr.tire.floor.iy) / tireSz};
}

void raycast(float tireX, float tireY)
{
  int hitWall;
  float dstX;
  float dstY;
  float posX;
  float posY;

  hitWall = 0;
  dstX = 0;
  dstY = 0;
  mstr.ray.sideDst.x = 0;
  mstr.ray.sideDst.y = 0;
  posX = (mstr.ray.tire.ix + mstr.ray.pcnt.x);
  posY = (mstr.ray.tire.iy + mstr.ray.pcnt.y);
  mstr.ray.deltaDst.x = fabs(1 / mstr.ray.rayDir.x);
  mstr.ray.deltaDst.y = fabs(1 / mstr.ray.rayDir.y);
  // printf("deltaDstX %f\n", mstr.ray.deltaDstX);
  // printf("deltaDstY %f\n", mstr.ray.deltaDstY);
  if (mstr.ray.rayDir.x < 0)
  {
    // printf("zzz1\n");
    mstr.ray.step.ix = -1;
    mstr.ray.sideDst.x = (posX - mstr.ray.tire.ix) * mstr.ray.deltaDst.x;
    // printf("sideDstX %f\n", mstr.ray.sideDstX);
  }
  else
  {
    // printf("zzz2\n");
    mstr.ray.step.ix = 1;
    mstr.ray.sideDst.x = ((mstr.ray.tire.ix + 1.0) - posX) * mstr.ray.deltaDst.x;
    // printf("sideDstX %f\n", mstr.ray.sideDstX);
  }
  if (mstr.ray.rayDir.y < 0)
  {
    // printf("zzz3\n");
    mstr.ray.step.iy = -1;
    mstr.ray.sideDst.y = (posY - mstr.ray.tire.iy) * mstr.ray.deltaDst.y;
    // printf("sideDstY %f\n", mstr.ray.sideDstY);
  }
  else
  {
    // printf("zzz4\n");
    mstr.ray.step.iy = 1;
    mstr.ray.sideDst.y = ((mstr.ray.tire.iy + 1.0) - posY) * mstr.ray.deltaDst.y;
    // printf("sideDstY %f\n", mstr.ray.sideDstY);
  }
  while (hitWall == 0)
  {
    if (mstr.ray.sideDst.x < mstr.ray.sideDst.y)
    {
      mstr.ray.isX = 1;
      // printf("Choose sideX sideX:%f < sideY: %f\n", mstr.ray.sideDstX, mstr.ray.sideDstY);
      //  tireX += mstr.ray.stepX * 0.5;
      tireX += mstr.ray.step.ix;
      dstX = mstr.ray.sideDst.x;
      // mstr.ray.sideDstX += (mstr.map.tireSz * mstr.ray.deltaDstX);
      // mstr.ray.sideDstX += (mstr.ray.deltaDstX * 30);
      mstr.ray.sideDst.x += (mstr.ray.deltaDst.x);
      // printf("Choose sideX2 sideX2:%f < sideY2: %f\n", sideDstX2, sideDstY2);
      // dstX2 = sideDstX2;
      // sideDstX2 += deltaDstX2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    else
    {
      mstr.ray.isX = 0;
      // printf("Choose sideY sideY:%f < sideX: %f\n", mstr.ray.sideDstY, mstr.ray.sideDstX);
      //  tireY += mstr.ray.stepY * 0.5;
      tireY += mstr.ray.step.iy;
      dstY = mstr.ray.sideDst.y;
      // mstr.ray.sideDstY += (mstr.map.tireSz * mstr.ray.deltaDstY);
      // mstr.ray.sideDstY += (mstr.ray.deltaDstY * 30);
      mstr.ray.sideDst.y += (mstr.ray.deltaDst.y);
      // printf("Choose sideY2 sideY2:%f < sideX2: %f\n", sideDstY2, sideDstX2);
      // dstY2 = sideDstY2;
      // sideDstY2 += deltaDstY2;
      // printf("map[%f][%f]\n", tireY, tireX);
    }
    if (input_ok(tireX, tireY))
      if (mstr.map.map[(int)tireY][(int)tireX] == '1')
      {
        //   printf("hit wall map[%i][%i] ", (int)tireY, (int)tireX);
        mstr.ray.hit.ix = tireX;
        mstr.ray.hit.iy = tireY;
        // find_limit_pos(tireX, tireY);
        hitWall = 1;
      }
  }
  if (hitWall == 1 && mstr.ray.camX == 0)
    drawRay();
  if (hitWall)
  {
    // printf("hit wall map[%i][%i] ", (int)tireY, (int)tireX);
    if (mstr.ray.isX)
      mstr.ray.ppwd = (mstr.ray.sideDst.x - mstr.ray.deltaDst.x);
    else
      mstr.ray.ppwd = (mstr.ray.sideDst.y - mstr.ray.deltaDst.y);
    // printf("ray%i:ppwd is %f\n", mstr.ray.rayN, mstr.ray.ppwd);
  }
}

void raycast2(void)
{
  int x;

  x = 0;
  mstr.ray.camX = 0;
  printf("//////plane rotate/////\n");
  mstr.ray.plane = rotate(mstr.ray.plane);
  printf("\n/////dir rotate/////\n");
  mstr.ray.dir = rotate(mstr.ray.dir);
  percentTire();
  printf("\n\n");
  while (x < SC_W)
  {
    mstr.ray.rayN = x;
    mstr.ray.camX = ((2 * x) / (float)SC_W) - 1;
    mstr.ray.rayDir.x = mstr.ray.dir.x + (mstr.ray.plane.x * FOV * mstr.ray.camX);
    mstr.ray.rayDir.y = mstr.ray.dir.y + (mstr.ray.plane.y * FOV * mstr.ray.camX);
    raycast(mstr.ray.tire.ix, mstr.ray.tire.iy);
    ++x;
  }
  mstr.ray.isX = -1;
  mstr.ray.rayN = -1;
  mstr.rot.rad = 0;

  // printf("rad %f\n", mstr.rot.rad);
  // printf("player posX: %f posY: %f\n", mstr.ray.pos.x, mstr.ray.pos.y);
  // printf("ceilX: %i ceilY: %i\n", mstr.tire.ceil.ix, mstr.tire.ceil.iy);
  // printf("floorX: %i floorY: %i\n", mstr.tire.floor.ix, mstr.tire.floor.iy);
  // printf("PercentX: %f PercentY: %f\n", mstr.ray.pcnt.x, mstr.ray.pcnt.y);
  // printf("player current tire (x:%i, y:%i)\n", mstr.ray.tire.ix, mstr.ray.tire.iy);
  // printf("map[%i][%i] is %i\n", mstr.ray.tire.iy, mstr.ray.tire.ix, mstr.map.map[mstr.ray.tire.iy][mstr.ray.tire.ix]);
  printf("dirX: %f dirY: %f\n", mstr.ray.dir.x, mstr.ray.dir.y);
}