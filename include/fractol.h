#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

typedef struct  s_complex
{
    double      r;
    double      i;
}               t_complex;

typedef struct  s_image
{
    void        *img;
    char        *addr;
    int			width;
    int			height;
    int         bpp;
    int         line_length;
    int         endian;
}               t_image;

typedef struct	s_fractal
{
    void		*mlx;
    void		*win;
    t_image		img;
    int			width;
    int			height;
    int			max_iter;
    double		zoom;
    double		x1;
    double		x2;
    double		y1;
    double		y2;
    t_complex    c;
    t_complex    z;
    double		tmp;
    int			i;
    int			color;
    char        *name;
}				t_fractal;

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

//main
int main(int argc, char **argv);

//calculation
void    mandelbrot(t_fractol *fractol);
void    julia(t_fractol *fractol, int x, int y);

//graphics


//utils

#endif


