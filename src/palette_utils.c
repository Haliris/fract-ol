/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:38:13 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(t_fractole *f, int pixel_index, double iter)
{
	int		col_core;
	int		col_in;
	int		col_out;
	int		final_col;
	double	ratio;

	col_core = f->palette->core;
	col_in = f->palette->in;
	col_out = f->palette->out;
	ratio = 0.0;
	if (iter == f->max_iter)
		final_col = col_core;
	else
	{
		ratio = iter / f->max_iter;
		if (ratio >= 0.90)
			final_col = (ratio * (f->max_r - f->min_r)) * col_in;
		else if (ratio >= 0.10)
			final_col = (ratio * (f->max_r - f->min_r)) * (col_in - col_out);
		else
			final_col = col_out;
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
