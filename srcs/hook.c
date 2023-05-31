#include "cub3d.h"

int handle_key(int key_code)
{
    // ft_walkUp(); // up
    if (key_code == 53)
    {
        ft_close("Escape key is pressed, window is closed\n");
        return (0);
    }
    else if (key_code == 13)
        walkUp(mstr.ray.tire.ix, mstr.ray.tire.iy);
    else if (key_code == 0)
        walkLeft(mstr.ray.tire.ix, mstr.ray.tire.iy);
    else if (key_code == 2)
        walkRight(mstr.ray.tire.ix, mstr.ray.tire.iy);
    else if (key_code == 1)
        walkDown(mstr.ray.tire.ix, mstr.ray.tire.iy);
    else if (key_code == 123)
    {
        printf("rotate left\n");
        mstr.rot.rad = -0.1;
        re_draw();
    }
    else if (key_code == 124)
    {
        printf("rotate right\n");
        mstr.rot.rad = 0.1;
        re_draw();
    }
    printf("player current tire (x:%i, y:%i)\n", mstr.ray.tire.ix, mstr.ray.tire.iy);
    return (0);
}

int handle_cross(void)
{
    ft_close("Cross is pressed, window is closed\n");
    return (0);
}