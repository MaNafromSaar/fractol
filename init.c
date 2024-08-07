/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:01:44 by root              #+#    #+#             */
/*   Updated: 2024/08/02 15:55:18 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, fractal->img.width,
			fractal->img.height, fractal->name);
	fractal->img.img = mlx_new_image(fractal->mlx, fractal->img.width,
			fractal->img.height);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_length, &fractal->img.endian);
}

void	init_fractal(t_fractal *fractal, char **argv)
{
	fractal->max_iter = 42;
	fractal->zoom = 1.0;
	fractal->x1 = 0;
	fractal->x2 = 0;
	fractal->y1 = 0;
	fractal->y2 = 0;
	fractal->xlo = -2.5;
	fractal->xhi = 1;
	fractal->ylo = -1.25;
	fractal->yhi = 1.25;
	fractal->color.r = 20;
	fractal->color.g = 240;
	fractal->color.b = 60;
	fractal->name = argv[1];
	fractal->argv = argv;
	fractal->img.width = 1920;
	fractal->img.height = 1280;
	init_gradient(fractal);
	init_mlx(fractal);
}

void	init_gradient(t_fractal *fractal)
{
	if (fractal->gradient)
		free(fractal->gradient);
	fractal->gradient_size = 3;
	fractal->gradient = malloc(fractal->gradient_size * sizeof(t_color));
	fractal->gradient[0] = fractal->color;
	fractal->gradient[1] = (t_color){fractal->color.g, fractal->color.b,
		fractal->color.r};
	fractal->gradient[2] = (t_color){fractal->color.b, fractal->color.r,
		fractal->color.g};
}

void	init_julia(t_fractal *fractal, char **argv, int argc)
{
	if (argc < 4)
	{
		if (argc < 3)
			fractal->c.r = -0.8;
		else
			fractal->c.r = ft_atof(argv[2]);
		fractal->c.i = 0.156;
	}
	else
	{
		fractal->c.r = ft_atof(argv[2]);
		fractal->c.i = ft_atof(argv[3]);
	}
	fractal->z.r = 0;
	fractal->z.i = 0;
	if (fractal->xlo == -2.5)
	{
		fractal->xlo = -2;
		fractal->xhi = 2;
		fractal->ylo = -2;
		fractal->yhi = 2;
	}
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->c.r = fractal->xlo + (fractal->x1 / fractal->img.width)
		* (fractal->xhi - fractal->xlo);
	fractal->c.i = fractal->ylo + (fractal->y1 / fractal->img.height)
		* (fractal->yhi - fractal->ylo);
	fractal->z.r = 0;
	fractal->z.i = 0;
}
