/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:11:22 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:25:45 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_palette	*create_palette(char *mode)
{
	t_palette	*palette;

	palette = ft_calloc(1, sizeof(t_palette));
	if (!palette)
		return (NULL);
	if (ft_strncmp(mode, "default", 7) == 0)
	{
		palette->background = create_color(0, 0, 0);
		palette->outer = create_color(0, 0, 255);
		palette->outline = create_color(0, 255, 0);
		palette->core = create_color(255, 255, 255);
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
