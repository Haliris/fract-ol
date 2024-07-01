/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:35 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean(t_process *process)
{
	if (process->img)
		mlx_destroy_image(process->mlx, process->img);
	if (process->window)
		mlx_destroy_window(process->mlx, process->window);
	if (process->palette)
		free(process->palette);
	mlx_destroy_display(process->mlx);
	free(process->mlx);
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
		return (palette);
	if (ft_strncmp(mode, "default", 7 == 0))
	{
		palette->background = create_color(0, 0, 0);
		palette->outer = create_color(0, 0, 255);
		palette->outline = create_color(0, 255, 0);
		palette->core = create_color(255, 255, 255);	
	}
	return (palette);
}

void	initialize(t_process *p)
{
	p->size = WIDTH;
	p->mlx = mlx_init();
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->palette = create_palette("default");
	if (!p->img)
		clean(p);
	p->img_addr = NULL;
	if (!p->mlx)
	{
		clean(p);
		exit(EXIT_FAILURE);
	}
	p->window = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!p->window)
	{
		clean(p);
		exit(EXIT_FAILURE);
	}
}
