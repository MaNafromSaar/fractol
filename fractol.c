/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:02:45 by root              #+#    #+#             */
/*   Updated: 2024/08/16 08:56:30 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This project generates beautiful fractal structures and lets you navigate 
// and alter them. It uses a special X-window library which you have to 
// install first.

// - download and unpack the archive
//     in terminal run:
//     tar -zxvf minilibx_opengl.tgz
// - run the makefile
//     in terminal go to the new folder:
//     cd minilibx_opengl_20191021/
//     run the makefile
//     make

// now you can return to the project's main folder and run the program

// - compile it using the makefile
// - call it with the desired parameter(s):
//     ./fractol
//         mandelbrot
//         julia   (real part) (complex part)
//         tricorn
// - explore it using mouse and keys:
//     - mousewheel for centered zoom 
//     (don't go too fast with that as quality will crank up while zooming in)
//     - leftclick for a zoom that follows mouse position
//     - arrow keys for navigating (only works after some zooming obviously)
//     - q for increasing quality (i.e. max iterations)
//     - y for decreasing quality
//     - r for reset to initial values
//     - c to change color pattern
//     - ESC to close the window

// Have fun and enjoy the beauty of infinity!

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
	zoom(fractal, 0.8, 0, 0);
	choice(argv, argc, fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
	mlx_mouse_hook(fractal->win, mouse_event, fractal);
	mlx_key_hook(fractal->win, key_event, fractal);
	mlx_hook(fractal->win, 17, 1L << 17, exit_fractal, fractal);
	mlx_loop(fractal->mlx);
	exit_fractal(fractal);
	return (0);
}

void	choice(char **argv, int argc, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
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
