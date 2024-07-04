/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:53:37 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 11:30:56 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calculate_julia(double z_real, double z_imag, double max, t_fractole *f)
{
	double	iter;
	double	c_real;
	double	c_imag;
	double	real_temp;

	iter = 0;
	c_real = f->julia_consts[0];
	c_imag = f->julia_consts[1];
	while (z_real * z_real + z_imag * z_imag <= JULIA_ESCAPE && iter < max)
	{
		real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2.0 * z_real * z_imag + c_imag;
		z_real = real_temp;
		iter++;
	}
	return (iter);
}

double	iterate_julia(int x, int y, double max, t_fractole *f)
{
	double		real;
	double		imag;

	real = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	imag = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	return (calculate_julia(real, imag, max, f));
}

void	render_julia(t_fractole *f, int size_line, int bpp)
{
	int			x;
	int			y;
	double		iter;
	int			pixel_index;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			iter = iterate_julia(x, y, f->max_iter, f);
			pixel_index = PIXEL_INDEX(x, y, size_line, bpp);
			put_color(f, pixel_index, iter);
			x++;
		}
		x = 0;
		y++;
	}
}
