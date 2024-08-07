/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:10:58 by root              #+#    #+#             */
/*   Updated: 2024/08/02 15:50:10 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && (*s1 && n) > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

double	ft_atof(char *str)
{
	double	res;
	double	div;
	int		sign;

	res = 0;
	div = 1;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str == '.')
			div = 10;
		else if (*str >= '0' && *str <= '9')
		{
			if (div == 1)
				res = res * 10 + (*str - '0') / div;
			else
			{
				res += (*str - '0') / div;
				div *= 10;
			}
		}
		str++;
	}
	return (res * sign);
}

int	exit_fractal(t_fractal *fractal)
{
	if (fractal)
	{
		if (fractal->img.img && fractal->mlx)
		{
			mlx_destroy_image(fractal->mlx, fractal->img.img);
			fractal->img.img = NULL;
		}
		if (fractal->win && fractal->mlx)
		{
			mlx_destroy_window(fractal->mlx, fractal->win);
			fractal->win = NULL;
		}
		if (fractal->gradient)
		{
		// 	free(fractal->gradient->b);
		// 	free(fractal->gradient->g);
		// 	free(fractal->gradient->r);
			free(fractal->gradient);
			fractal->gradient = NULL;
		}
		// if (fractal->mlx)
		// {
		// 	free(fractal->mlx);
		// 	fractal->mlx = NULL;
		// }
		if (fractal)
			free(fractal);
		fractal = NULL;
	}
	exit(0);
}


int	handle_exit(t_fractal *fractal)
{
	exit_fractal(fractal);
	return (0);
}
