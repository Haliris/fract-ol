/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/03 16:33:47 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_color(t_fractole *f, int pixel_index, double iter)
{
	int	color_core;
	int	color_in;
	int	color_out;

	color_core = f->palette->core;
	color_in = f->palette->in;
	color_out = f->palette->out;
	if (iter == f->max_iter)
	 	*(int *)(f->img_addr + pixel_index) = color_core;
	else if (iter >= f->max_iter * 0.80)
		*(int *)(f->img_addr + pixel_index) = iter * color_in;
	else if (iter >= f->max_iter * 0.30)
	 	*(int *)(f->img_addr + pixel_index) = iter * color_out;
}
	// t_palette	*palette;

	// palette = f->palette;
	// if (iter == f->max_iter)
	// 	*(int *)(f->img_addr + pixel_index) = palette->core;
	// else if (iter >= f->max_iter * 0.80)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outline_1;
	// else if (iter >= f->max_iter * 0.70)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outline_2;
	// else if (iter >= f->max_iter * 0.60)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outline_3;
	// else if (iter >= f->max_iter * 0.50)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outline_4;
	// else if (iter >= f->max_iter * 0.40)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outline_5;
	// else if (iter >= f->max_iter * 0.30)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outer_1;
	// else if (iter >= f->max_iter * 0.20)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outer_2;
	// else if (iter >= f->max_iter * 0.15)
	// 	*(int *)(f->img_addr + pixel_index) = palette->outer_3;
	// else
	// 	*(int *)(f->img_addr + pixel_index) = palette->outer_4;


void	make_starry_night(t_palette *palette)
{
	palette->core = create_color(255, 255, 255);
	palette->out = create_color(102, 102, 255);
	palette->in = create_color(102, 0, 0);
	// palette->outer_1 = create_color(102, 102, 255);
	// palette->outer_2 = create_color(51, 51, 255);
	// palette->outer_3 = create_color(0, 0, 153);
	// palette->outer_4 = create_color(0, 0, 102);
	// palette->outline_1 = create_color(102, 0, 0);
	// palette->outline_2 = create_color(255, 0, 0);
	// palette->outline_3 = create_color(255, 128, 0);
	// palette->outline_4 = create_color(255, 255, 51);
	// palette->outline_5 = create_color(255, 255, 204);
}

void	make_psychedelic(t_palette *palette)
{
	palette->core = create_color(255, 51, 153);
	palette->out = create_color(0, 255, 0);
	palette->in = create_color(255, 255, 102);
	// palette->outer_1 = create_color(0, 255, 0);
	// palette->outer_2 = create_color(51, 51, 255);
	// palette->outer_3 = create_color(204, 204, 255);
	// palette->outer_4 = create_color(255, 255, 255);
	// palette->outline_1 = create_color(255, 255, 102);
	// palette->outline_2 = create_color(51, 255, 255);
	// palette->outline_3 = create_color(51, 255, 153);
	// palette->outline_4 = create_color(127, 0, 255);
	// palette->outline_5 = create_color(128, 255, 0);
}

void	make_firestorm(t_palette *palette)
{
	palette->core = create_color(102, 0, 0);
	palette->out = create_color(255, 128, 0);
	palette->in = create_color(255, 0, 0);
	// palette->outer_1 = create_color(255, 128, 0);
	// palette->outer_2 = create_color(255, 102, 102);
	// palette->outer_3 = create_color(255, 255, 102);
	// palette->outer_4 = create_color(51, 0, 0);
	// palette->outline_1 = create_color(255, 0, 0);
	// palette->outline_2 = create_color(204, 102, 102);
	// palette->outline_3 = create_color(204, 0, 0);
	// palette->outline_4 = create_color(255, 153, 51);
	// palette->outline_5 = create_color(255, 255, 51);
}

t_palette	*create_palette(char *mode)
{
	t_palette	*palette;

	palette = ft_calloc(1, sizeof(t_palette));
	if (!palette)
		return (NULL);
	if (ft_strncmp(mode, "default", 7) == 0)
		make_starry_night(palette);
	if (ft_strncmp(mode, "psychedelic", 11) == 0)
		make_psychedelic(palette);
	if (ft_strncmp(mode, "firestorm", 9) == 0)
		make_firestorm(palette);
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
