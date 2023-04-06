#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"

typedef struct s_vector 
{
    int x;
    int y;
}              t_vector;

typedef struct s_img
{
    void *img;
    int *addr;
    int bpp;
    int line_len;
    int endian;
}              t_img;

typedef struct s_vars
{
    void *mlx;
    void *win;
}              t_vars;
