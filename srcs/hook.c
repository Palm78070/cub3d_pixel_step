#include "cub3d.h"

int handle_key(int key_code)
{
    if (key_code == 53)
    {
        ft_close("Escape key is pressed, window is closed\n");
        return (0);
    }
    else if (key_code == 13)
        ft_walkUp(); // up
    else if (key_code == 0)
        ft_walkLeft(); // left
    else if (key_code == 2)
        ft_walkRight(); // right
    else if (key_code == 1)
        ft_walkDown(); // down
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