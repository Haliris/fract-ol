/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/03 18:35:37 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int interpolate_color(int color1, int color2, double t)
{
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    int r = (int)(r1 + (r2 - r1) * t);
    int g = (int)(g1 + (g2 - g1) * t);
    int b = (int)(b1 + (b2 - b1) * t);

    return create_color(r, g, b);
}

void	put_color(t_fractole *f, int pixel_index, double iter)
{
	int	color_core;
	int	color_in;
	int	color_out;
	int color_to_put;
	double	ratio;

	color_core = f->palette->core;
	color_in = f->palette->in;
	color_out = f->palette->out;
	ratio = 0.0;
	if (iter == f->max_iter)
		color_to_put = color_core;
	else
	{
		ratio = iter / f->max_iter;
		if (ratio >= 0.90)
			color_to_put = interpolate_color(color_in, color_core, (ratio - 0.90) / 0.25);
		else if (ratio >= 0.75)
			color_to_put = interpolate_color(color_out, color_in, (ratio - 0.75) / 0.25);
		else
			color_to_put = interpolate_color(color_out, color_in, (ratio / 0.90));
	}
 	*(int *)(f->img_addr + pixel_index) = color_to_put;
}

void	make_starry_night(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(102, 102, 255);
	palette->in = create_color(102, 0, 0);
}

void	make_psychedelic(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(255, 153, 255);
	palette->in = create_color(255, 255, 51);
}

void	make_firestorm(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(255, 128, 0);
	palette->in = create_color(102, 0, 0);
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
