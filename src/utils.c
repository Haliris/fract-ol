/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:16:07 by jteissie         ###   ########.fr       */
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

void	initialize(t_fractole *f)
{
	f->size = WIDTH;
	f->mlx = mlx_init();
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->palette = NULL;
	swap_palette(f, "default");
	f->img_addr = NULL;
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->mlx || !f->img || !f->palette || !f->window)
	{
		clean(f);
		exit(EXIT_FAILURE);
	}
}
