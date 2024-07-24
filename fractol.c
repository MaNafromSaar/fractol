/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:02:45 by root              #+#    #+#             */
/*   Updated: 2024/07/17 15:34:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || argc > 4 || (ft_strncmp(argv[1], "mandelbrot", 10) != 0
			&& ft_strncmp(argv[1], "julia", 5) != 0
			&& ft_strncmp(argv[1], "tricorn", 7) != 0))
	{
		write(1, "Usage: ./fractol mandelbrot/tricorn/julia (param1 param2)\n",
			59);
		exit(0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (fractal == NULL)
		return (0);
	init_fractal(fractal, argv);
	choice(argv, argc, fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
	mlx_mouse_hook(fractal->win, mouse_event, fractal);
	mlx_key_hook(fractal->win, key_event, fractal);
	mlx_hook(fractal->win, 17, 1L << 17, handle_exit, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

void	choice(char **argv, int argc, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0) // && argc == 2)
		mandelbrot(fractal);
	else if (ft_strncmp(argv[1], "j", 1) == 0)
	{
		init_julia(fractal, argv, argc);
		julia(fractal);
	}
	else
	{
		init_tricorn(fractal);
		tricorn(fractal);
	}
}
