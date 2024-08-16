/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:06:46 by root              #+#    #+#             */
/*   Updated: 2024/08/07 17:39:33 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	color_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

t_color	interpolate_color(t_color col1, t_color col2, double fraction)
{
	t_color	result;

	result.r = col1.r + (col2.r - col1.r) * fraction;
	result.g = col1.g + (col2.g - col1.g) * fraction;
	result.b = col1.b + (col2.b - col1.b) * fraction;
	return (result);
}

t_color	get_color(int iter, t_fractal *fractal)
{
	double	fraction;
	int		index;
	double	intrafraction;

	fraction = (double)iter / (double)fractal->max_iter;
	index = fraction * (fractal->gradient_size - 1);
	intrafraction = (fraction * (fractal->gradient_size - 1)) - index;
	return (interpolate_color(fractal->gradient[index], fractal->gradient[(index
					+ 1) % fractal->gradient_size], intrafraction));
}

void	refresh(t_fractal *fractal)
{
	if (fractal->img.img != NULL)
		mlx_destroy_image(fractal->mlx, fractal->img.img);
	fractal->img.img = mlx_new_image(fractal->mlx, fractal->img.width,
			fractal->img.height);
	if (fractal->img.img == NULL)
		exit(1);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_length, &fractal->img.endian);
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
		julia(fractal);
	else if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		mandelbrot(fractal);
	else
		tricorn(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
	mlx_do_sync(fractal->mlx);
}
