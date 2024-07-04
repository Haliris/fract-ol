/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 15:58:45 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_random(t_fractole *f, int pixel_index, double iter)
{
	int		col_core;
	int		col_in;
	int		col_out;
	int		final_col;
	double	ratio;

	col_core = f->palette->core;
	col_in = f->palette->in;
	col_out = f->palette->out;
	ratio = iter / f->max_iter;
	if (iter == f->max_iter)
		final_col = col_core;
	else
	{
		if (ratio >= 0.90)
			final_col = (ratio * (f->max_r - f->min_r)) * col_in;
		else if (ratio >= 0.10)
			final_col = (ratio * (f->max_r - f->min_r)) * (col_in - col_out);
		else
			final_col = col_out;
	}
	*(int *)(f->img_addr + pixel_index) = final_col;
}

void	put_color_inter(t_fractole *f, int pixel_index, double iter)
{
	int		col_core;
	int		col_in;
	int		col_out;
	int		final_col;
	double	ratio;

	col_core = f->palette->core;
	col_in = f->palette->in;
	col_out = f->palette->out;
	ratio = iter / f->max_iter;
	if (iter == f->max_iter)
		final_col = col_core;
	else
	{
		if (ratio >= 0.90)
			final_col = interpolate_color(col_in, col_core, (ratio - 0.90));
		else
			final_col = interpolate_color(col_out, col_in, (ratio));
	}
	*(int *)(f->img_addr + pixel_index) = final_col;
}

void	swap_palette(t_fractole *f, char *mode)
{
	if (f->palette)
		free(f->palette);
	f->palette = create_palette(mode);
	if (!f->palette)
		return ;
}
