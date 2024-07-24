/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:12:35 by root              #+#    #+#             */
/*   Updated: 2024/07/17 15:22:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_image		img;
	int			max_iter;
	double		zoom;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		xlo;
	double		xhi;
	double		ylo;
	double		yhi;
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;
	t_color		color;
	t_color		*gradient;
	int			gradient_size;
	char		*name;
	char		**argv;
}				t_fractal;

// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define Q 113
# define Y 121
# define P 112

// MOUSECODES
# define LEFTCLICK 1
# define RIGHTCLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// main
int				main(int argc, char **argv);

// calculation
void			mandelbrot(t_fractal *fractal);
void			julia(t_fractal *fractal);
void			tricorn(t_fractal *fractal);
void			calculate_tricorn(t_fractal *fractal);
void			calculate_mandelbrot(t_fractal *fractal);
void			calculate_julia(t_fractal *fractal);
void			get_tricorn_values(t_fractal *fractal);

// graphics
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
void			mandelbrot(t_fractal *fractal);
int				color_to_int(t_color color);
t_color			get_color(int iter, t_fractal *fractal);
void			refresh(t_fractal *fractal);
void			init_gradient(t_fractal *fractal);
t_color			interpolate_color(t_color col1, t_color col2, double fraction);
void			color_wrap(int i, t_fractal *fractal);
void			init_mandelbrot(t_fractal *fractal);

// operations
int				mouse_event(int button, int x, int y, void *param);
int				key_event(int keycode, t_fractal *fractal);
void			reset(t_fractal *fractal);
void			zoom(t_fractal *fractal, double zoom, int x, int y);
int				exit_fractal(t_fractal *fractal);
void			zoom_julia(t_fractal *fractal, double zoom, int x, int y);

// utils
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			init_mlx(t_fractal *fractal);
void			init_fractal(t_fractal *fractal, char **argv);
void			init_julia(t_fractal *fractal, char **argv, int argc);
void			init_tricorn(t_fractal *fractal);
double			ft_atof(char *str);
void			choice(char **argv, int argc, t_fractal *fractal);
int				handle_exit(t_fractal *fractal);

#endif
