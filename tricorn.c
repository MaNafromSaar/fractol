/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:51:15 by root              #+#    #+#             */
/*   Updated: 2024/07/17 14:26:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_tricorn(t_fractal *fractal)
{
	if (fractal->xlo == -2.5 && fractal->xhi == 1)
	{
		fractal->xlo = -2.5;
		fractal->xhi = 2.5;
		fractal->ylo = -2.5;
		fractal->yhi = 2.5;
		fractal->img.width = 1000;
		fractal->img.height = 1000;
		fractal->max_iter = 90;
	}
}

void	get_tricorn_values(t_fractal *fractal)
{
	fractal->z.r = fractal->xlo
		+ (fractal->x1 / (double)fractal->img.width)
		* (fractal->xhi - fractal->xlo);
	fractal->z.i = fractal->ylo + (fractal->y1 / (double)fractal->img.height)
		* (fractal->yhi - fractal->ylo);
	fractal->c.r = fractal->z.r;
	fractal->c.i = fractal->z.i;
}

void	calculate_tricorn(t_fractal *fractal)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	get_tricorn_values(fractal);
	i = 0;
	while (fractal->z.r * fractal->z.r + fractal->z.i * fractal->z.i < 4
		&& ++i < fractal->max_iter)
	{
		tmp = fractal->z.r;
		zr = fractal->z.r * fractal->z.r - fractal->z.i * fractal->z.i
			+ fractal->c.r;
		zi = -2 * fractal->z.i * tmp + fractal->c.i;
		fractal->z.r = zr;
		fractal->z.i = zi;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(&fractal->img, fractal->x1, fractal->y1, 0x000000);
	else
		color_wrap(i, fractal);
}

void	tricorn(t_fractal *fractal)
{
	fractal->x1 = 0;
	while (fractal->x1 < fractal->img.width)
	{
		fractal->y1 = 0;
		while (fractal->y1 < fractal->img.height)
		{
			calculate_tricorn(fractal);
			fractal->y1++;
		}
		fractal->x1++;
	}
}
