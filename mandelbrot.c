#include "/include/fractol.h"

void    calculate_mandelbrot(t_fractal *fractal)
{
    int     i;
    double  tmp;
    double  zr;
    double  zi;

    fractal->c_r = fractal->x / fractal->zoom + fractal->x1;
    fractal->c_i = fractal->y / fractal->zoom + fractal->y1;
    fractal->z_r = 0;
    fractal->z_i = 0;
    i = -1;
    while (fractal->z_r * fractal->z_r + fractal->z_i * fractal->z_i < 4
        && ++i < fractal->max_iter)
    {
        tmp = fractal->z_r;
        zr = fractal->z_r * fractal->z_r - fractal->z_i * fractal->z_i + fractal->c_r;
        zi = 2 * fractal->z_i * tmp + fractal->c_i;
        fractal->z_r = zr;
        fractal->z_i = zi;
    }
    if (i == fractal->max_iter)
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
    else
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, fractal->color * i);
}