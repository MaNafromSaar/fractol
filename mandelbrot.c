/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:09:27 by root              #+#    #+#             */
/*   Updated: 2024/07/16 16:00:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	init_mandelbrot(fractal);
	i = 0;
	while (fractal->z.r * fractal->z.r + fractal->z.i * fractal->z.i < 4
		&& ++i < fractal->max_iter)
	{
		tmp = fractal->z.r;
		zr = fractal->z.r * fractal->z.r - fractal->z.i * fractal->z.i
			+ fractal->c.r;
		zi = 2 * fractal->z.i * tmp + fractal->c.i;
		fractal->z.r = zr;
		fractal->z.i = zi;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(&fractal->img, fractal->x1, fractal->y1, 0x000000);
	else
		color_wrap(i, fractal);
}

void	mandelbrot(t_fractal *fractal)
{
	fractal->x1 = 0;
	while (fractal->x1 < fractal->img.width)
	{
		fractal->y1 = 0;
		while (fractal->y1 < fractal->img.height)
		{
			calculate_mandelbrot(fractal);
			fractal->y1++;
		}
		fractal->x1++;
	}
}
