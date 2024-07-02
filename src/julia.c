/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:53:37 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 15:01:31 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(const double c_real, const double c_imag)
{
	int		iter;
	double	z_real;
	double	z_imag;
	double	real_temp;

	iter = 0;
	z_imag = 0;
	z_real = 0;
	while (z_real * z_real + z_imag * z_imag <= JULIA_ESCAPE && iter < MAX_ITER)
	{
		real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2.0 * z_real * z_imag + c_imag;
		z_real = real_temp;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fractole *f, int size_line, int bpp)
{
	int			x;
	int			y;
	double		real;
	double		imag;
	int			iter;
	int			pixel_index;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			real = ((x - WIDTH / 2.0) * 4.0 / WIDTH);
			imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT);
			pixel_index = PIXEL_INDEX(x, y, size_line, bpp);
			iter = iterate_julia(real, imag);
			put_color(f, pixel_index, iter);
			x++;
		}
		x = 0;
		y++;
	}
}
