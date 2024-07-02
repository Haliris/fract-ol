/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 15:05:18 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_color(t_fractole *f, int pixel_index, int iter)
{
	t_palette	*palette;

	palette = f->palette;
	if (iter == MAX_ITER)
		*(int *)(f->img_addr + pixel_index) = palette->core;
	else if (iter >= 50)
		*(int *)(f->img_addr + pixel_index) = palette->outline_1;
	else if (iter >= 25)
		*(int *)(f->img_addr + pixel_index) = palette->outline_2;
	else if (iter >= 10)
		*(int *)(f->img_addr + pixel_index) = palette->outer_1;
	else if (iter >= 5)
		*(int *)(f->img_addr + pixel_index) = palette->outer_2;
	else if (iter >= 4)
		*(int *)(f->img_addr + pixel_index) = palette->outer_3;
	else if (iter >= 3)
		*(int *)(f->img_addr + pixel_index) = palette->outer_4;
	else
		*(int *)(f->img_addr + pixel_index) = palette->background;
}

t_palette	*create_palette(char *mode)
{
	t_palette	*palette;

	palette = ft_calloc(1, sizeof(t_palette));
	if (!palette)
		return (NULL);
	if (ft_strncmp(mode, "default", 7) == 0)
	{
		palette->outer_1 = create_color(153, 0, 76);
		palette->outer_2 = create_color(255, 153, 255);
		palette->outer_3 = create_color(102, 0, 204);
		palette->outer_4 = create_color(178, 102, 255);
		palette->background = create_color(255, 255, 255);
		palette->outline_1 = create_color(255, 255, 0);
		palette->outline_2 = create_color(153, 51, 255);
		palette->core = create_color(0, 0, 0);
	}
	return (palette);
}

void	swap_palette(t_fractole *f, char *mode)
{
	if (f->palette)
		free(f->palette);
	f->palette = create_palette(mode);
	if (!f->palette)
		return ;
}
