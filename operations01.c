/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:01:38 by root              #+#    #+#             */
/*   Updated: 2024/08/16 08:38:05 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, double zoom, int x, int y)
{
	double	center_x;
	double	center_y;

	if (fractal == NULL)
		exit_fractal(fractal);
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
	if (fractal->max_iter * zoom < 150 && fractal->max_iter > 10)
		fractal->max_iter /= zoom;
}

static void	move(int keycode, t_fractal *fractal)
{
	double	x;
	double	y;

	x = (fractal->xhi - fractal->xlo) / 10;
	y = (fractal->yhi - fractal->ylo) / 10;
	if (keycode == UP && fractal->yhi + y <= fractal->yhi + 1)
	{
		fractal->ylo -= y;
		fractal->yhi -= y;
	}
	else if (keycode == DOWN && fractal->ylo - y >= fractal->ylo - 1)
	{
		fractal->ylo += y;
		fractal->yhi += y;
	}
	else if (keycode == LEFT && fractal->xlo - x >= fractal->xlo - 1)
	{
		fractal->xlo -= x;
		fractal->xhi -= x;
	}
	else if (keycode == RIGHT && fractal->xhi + x <= fractal->xhi + 1)
	{
		fractal->xlo += x;
		fractal->xhi += x;
	}
}

int	key_event(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		exit_fractal(fractal);
	else if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		move(keycode, fractal);
	else if (keycode == R)
		reset(fractal);
	else if (keycode == C)
	{
		fractal->color.r = rand() % 255;
		fractal->color.g = rand() % 255;
		fractal->color.b = rand() % 255;
		init_gradient(fractal);
	}
	else if (keycode == Q && fractal->max_iter < 666)
		fractal->max_iter += 20;
	else if (keycode == Y && fractal->max_iter > 20)
		fractal->max_iter -= 10;
	refresh(fractal);
	return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (button == SCROLL_UP)
		zoom(fractal, 0.618, -1000, -1000);
	else if (button == SCROLL_DOWN)
		zoom(fractal, 1.618, -1000, -1000);
	if (button == LEFTCLICK)
	{
		if (fractal->name[0] == 'j' || fractal->name[0] == 't')
			zoom_julia(fractal, 0.618, x, y);
		else
			zoom(fractal, 0.618, x, y);
	}
	else if (button == RIGHTCLICK)
	{
		if (fractal->name[0] == 'j' || fractal->name[0] == 't')
			zoom_julia(fractal, 1.618, x, y);
		else
			zoom(fractal, 1.618, x, y);
	}
	refresh(fractal);
	return (0);
}
