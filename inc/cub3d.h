/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:51:07 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 22:09:40 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#define FLT_MIN 1.175494351e-38F
#define FLT_MAX 3.402823466e+38F
#define SC_W 640
#define SC_H 480
#define MnMp_W 200
#define MnMp_H 200
#define tireSz 20
#define texSz 200
#define FOV 0.66
#define STEP 5

typedef struct s_mapinfo
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *ceil;
    char *flor;
    char **map;
    char **tmp;
    int mapW;
    int mapH;
} t_mapinfo;

typedef struct s_mlx
{
    void *ptr;
    void *win;
    void *img_ptr;
    char *img_addr;
    int bpp;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_point
{
    float x;
    float y;
    int ix;
    int iy;
} t_point;

typedef struct s_minimap
{
    void *img;
    char *rl_path;
    int imgW;
    int imgH;
    t_point floor;
    t_point ceil;
    t_point start;
    t_point tmpPos;
} t_minimap;

typedef struct s_vec
{
    float x;
    float y;
    int ix;
    int iy;
} t_vec;

typedef struct s_ray
{
    t_point tire;
    t_point hit;
    t_point img_pos;
    t_point step;
    t_point lmt;
    t_point pcnt;
    t_point tex;
    t_vec pos;
    t_vec dir;
    t_vec plane;
    t_vec rayDir;
    t_vec deltaDst;
    t_vec sideDst; // distance tha ray has to travel from its start pos to first x-side and first x,y-side
    int rayN;
    int isX;
    float camX;
    float ppwd;
    float wallHit;
} t_ray;

typedef struct s_rotate
{
    float rad;
} t_rotate;

typedef struct s_tire
{
    t_point floor;
    t_point ceil;
} t_tire;

typedef struct s_cub3d
{
    int color;
    t_mlx mlx;
    char **mapfile;
    t_list **tmpmap;
    t_mapinfo map;
    t_minimap mnMp;
    t_ray ray;
    t_rotate rot;
    t_tire tire;
} t_cub3d;

extern t_cub3d mstr;

// check map
int chkfilenamemap(int argc, char **argv);

// map error handling
void fileerrhand(int errnum);

// initial main struct
int initmstr(t_cub3d *mstr);
void find_player_dir(char c);

// save map into linklist
int storfile2tlist(char *mapfile, t_list **tmpmap);

// key word
int is_keyword(char c);
// save map from linklist to mapinfo
void stormapinfo(t_list *tmpmap, t_mapinfo *map);

// mlx
void mlx_setup();
// hook
int handle_key(int key_code);
int handle_cross(void);
int handle_walk(int key_code);
// walk_utils
void stepY(int dir, char c);
void stepX(int dir, char c);
int isHitWall(int x, int y);
// walk
void walkUp(int x, int y);
void walkDown(int x, int y);
void walkLeft(int x, int y);
void walkRight(int x, int y);
// crossTire
// int crossTire(char c);
int crossTire(int x, int y);
// hitWall
int hitWall(char c);
// draw
void ft_pixel_put(int x, int y, int color);
int dn(int n0, int n1);
void line(float x0, float y0, float x1, float y1);
// minimap_utils
int input_ok(int tireX, int tireY);
void flood_tire(void);
void re_init_map(void);
// minimap
void draw_tire(t_point p, int tireX, int tireY);
void draw_wall(t_point p);
void draw_minimap(int x, int y);
void re_draw(void);
// draw_tire
void lineT(t_point p0, t_point p1);
// void draw_tire2(t_point p, int mode);
//  raycasting
void raycast(float tireX, float tireY);
void raycast2(void);
// texture.c
void getTextPoint(void);
// clear
void ft_clear(void);
void ft_error(char *s);
void ft_close(char *s);
#endif
