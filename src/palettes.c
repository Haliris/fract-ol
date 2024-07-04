/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:36:51 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 16:03:02 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	make_starry_night(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(0, 0, 51);
	palette->in = create_color(255, 255, 102);
}

void	make_psychedelic(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(255, 255, 255);
	palette->in = create_color(204, 0, 204);
}

void	make_firestorm(t_palette *palette)
{
	palette->core = create_color(0, 0, 0);
	palette->out = create_color(255, 178, 102);
	palette->in = create_color(153, 0, 0);
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
	palette->scheme = INTERPOLATE;
	return (palette);
}
