/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:31:47 by root              #+#    #+#             */
/*   Updated: 2024/08/15 17:07:31 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

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

void	julia(t_fractal *fractal)
{
	fractal->x1 = 0;
	while (fractal->x1 < fractal->img.width)
	{
		fractal->y1 = 0;
		while (fractal->y1 < fractal->img.height)
		{
			fractal->z.r = fractal->xlo
				+ (fractal->x1 / (double)fractal->img.width)
				* (fractal->xhi - fractal->xlo);
			fractal->z.i = fractal->ylo
				+ (fractal->y1 / (double)fractal->img.height)
				* (fractal->yhi - fractal->ylo);
			calculate_julia(fractal);
			fractal->y1++;
		}
		fractal->x1++;
	}
}
