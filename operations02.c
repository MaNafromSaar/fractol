/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:02:10 by root              #+#    #+#             */
/*   Updated: 2024/07/17 15:24:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->xlo = -2.5;
	fractal->xhi = 1;
	fractal->ylo = -1.25;
	fractal->yhi = 1.25;
	fractal->color.r = 20;
	fractal->color.g = 240;
	fractal->color.b = 60;
	init_gradient(fractal);
}

void	zoom_julia(t_fractal *fractal, double zoom, int x, int y)
{
	double	center_x;
	double	center_y;

	if (fractal == NULL)
		exit(1);
	if (x == -1000 && y == -1000)
	{
		center_x = (fractal->xlo + fractal->xhi) / 2;
		center_y = (fractal->ylo + fractal->yhi) / 2;
	}
	else
	{
		center_x = fractal->xlo + (fractal->xhi - fractal->xlo) * x
			/ fractal->img.width;
		center_y = fractal->ylo + (fractal->yhi - fractal->ylo) * y
			/ fractal->img.height;
	}
	fractal->xlo = center_x - (center_x - fractal->xlo) * zoom;
	fractal->xhi = center_x + (fractal->xhi - center_x) * zoom;
	fractal->ylo = center_y - (center_y - fractal->ylo) * zoom;
	fractal->yhi = center_y + (fractal->yhi - center_y) * zoom;
	fractal->zoom *= zoom;
	if (fractal->max_iter * zoom < 150)
		fractal->max_iter /= zoom;
}

void	zoom_tricorn(t_fractal *fractal, double zoom, int x, int y)
{
	double	center_x;
	double	center_y;

	if (fractal == NULL)
		exit(1);
	if (x == -1000 && y == -1000)
	{
		center_x = (fractal->xlo + fractal->xhi) / 2;
		center_y = (fractal->ylo + fractal->yhi) / 2;
	}
	else
	{
		center_x = fractal->xlo + (fractal->xhi - fractal->xlo) * x
			/ fractal->img.width;
		center_y = fractal->ylo + (fractal->yhi - fractal->ylo) * y
			/ fractal->img.height;
	}
	fractal->xlo = center_x - (center_x - fractal->xlo) * zoom;
	fractal->xhi = center_x + (fractal->xhi - center_x) * zoom;
	fractal->ylo = center_y - (center_y - fractal->ylo) * zoom;
	fractal->yhi = center_y + (fractal->yhi - center_y) * zoom;
	fractal->zoom *= zoom;
	if (fractal->max_iter * zoom < 150)
		fractal->max_iter /= zoom;
}
