#include "/include/fractol.h"

void    init_mlx(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, fractal->width, fractal->height, fractal->name);
    fractal->img.img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, 
            &fractal->img.bpp,
            &fractal->img.line_length,
            &fractal->img.endian);
}

void    init_fractal(t_fractal *fractal)
{
    fractal->max_iter = 42;
    fractal->zoom = 300;
    fractal->x1 = -2.0;
    fractal->x2 = 2.0;
    fractal->y1 = -2.0;
    fractal->y2 = 2.0;
    fractal->color = 265;
    fractal->name = argv[1];
    fractal->width = 800;
    fractal->height = 800;
}