/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:45:01 by root              #+#    #+#             */
/*   Updated: 2024/07/16 15:58:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_wrap(int i, t_fractal *fractal)
{
	int		color_int;
	t_color	color;

	color = get_color(i, fractal);
	color_int = color_to_int(color);
	my_mlx_pixel_put(&fractal->img, fractal->x1, fractal->y1, color_int);
}
