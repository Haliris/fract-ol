/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:10:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean(t_fractole *fractole)
{
	if (fractole->img)
		mlx_destroy_image(fractole->mlx, fractole->img);
	if (fractole->window)
		mlx_destroy_window(fractole->mlx, fractole->window);
	if (fractole->palette)
		free(fractole->palette);
	mlx_destroy_display(fractole->mlx);
	free(fractole->mlx);
	exit (EXIT_SUCCESS);
}

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_palette	*create_palette(char *mode)
{
	t_palette	*palette;

	palette = ft_calloc(1, sizeof(palette));
	if (!palette)
		return (NULL);
	if (ft_strncmp(mode, "default", 7 == 0))
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

void	initialize(t_fractole *f)
{
	f->size = WIDTH;
	f->mlx = mlx_init();
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->palette = create_palette("default");
	f->img_addr = NULL;
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->mlx || !f->img || !f->palette || !f->window)
	{
		clean(f);
		exit(EXIT_FAILURE);
	}
}
