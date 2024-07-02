/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:14 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 13:32:42 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(const double c_real, const double c_imag)
{
	int		iter;
	double	z_real;
	double	z_imag;
	int		escape_radius;
	double	real_temp;

	iter = 0;
	z_imag = 0;
	z_real = 0;
	escape_radius = MANDELBROT_ESCAPE * MANDELBROT_ESCAPE;
	while (z_real * z_real + z_imag * z_imag <= escape_radius && iter < MAX_ITER)
	{
		real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2.0 * z_real * z_imag + c_imag;
		z_real = real_temp;
		iter++;
	}
	return (iter);
}

void	render_mandelbrot(t_fractole *f, int size_line, int bpp)
{
	int			x;
	int			y;
	double		real;
	double		imag;
	int			iter;
	int			pixel_index;
	t_palette	*palette;

	y = 0;
	x = 0;
	palette = f->palette;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			real = ((x - WIDTH / 2.0) * 4.0 / WIDTH);
			imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT);
			pixel_index = PIXEL_INDEX(x, y, size_line, bpp);
			iter = iterate_mandelbrot(real, imag);
			if (iter == MAX_ITER)
				*(int *)(f->img_addr + pixel_index) = palette->core;
			else
				*(int *)(f->img_addr + pixel_index) = palette->background;
			x++;
		}
		x = 0;
		y++;
	}
}
