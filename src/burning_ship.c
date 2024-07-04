/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:10:54 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 15:54:15 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calculate_burning(const double c_real, const double c_imag, double max)
{
	double	iter;
	double	z_real;
	double	z_imag;
	double	real_temp;

	iter = 0;
	z_imag = 0;
	z_real = 0;
	while (z_real * z_real + z_imag * z_imag <= BURNING_ESCAPE && iter < max)
	{
		real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2.0 * fabs(z_real * z_imag) + c_imag;
		z_real = fabs(real_temp);
		iter++;
	}
	return (iter);
}

double	iterate_burning(int x, int y, double max, t_fractole *f)
{
	double		real;
	double		imag;

	real = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	imag = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	return (calculate_burning(real, imag, max));
}

void	render_burning(t_fractole *f, int size_line, int bpp)
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
			iter = iterate_burning(x, y, f->max_iter, f);
			pixel_index = PIXEL_INDEX(x, y, size_line, bpp);
			if (f->palette->scheme == RANDOM)
				put_color_random(f, pixel_index, iter);
			else
				put_color_inter(f, pixel_index, iter);
			x++;
		}
		x = 0;
		y++;
	}
}
