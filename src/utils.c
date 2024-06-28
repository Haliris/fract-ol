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
	if (process->window && process->mlx)
		mlx_destroy_window(process->mlx, process->window);
	mlx_destroy_display(process->mlx);
	free(process->mlx);
	exit (EXIT_SUCCESS);
}

void	initialize(t_process *p)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	p->size = 700;
	p->mlx = mlx_init();
	p->img = mlx_new_image(p->mlx, 700, 700);
	if (!p->img)
		clean(p);
	p->img_addr = mlx_get_data_addr(p->img, &pixel_bits, &line_bytes, &endian);
	if (!p->mlx)
	{
		clean(p);
		exit(EXIT_FAILURE);
	}
	p->window = mlx_new_window(p->mlx, 700, 700, "Fract-ol");
	if (!p->window)
	{
		clean(p);
		exit(EXIT_FAILURE);
	}
}
