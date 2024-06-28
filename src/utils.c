/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 15:29:19 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean(t_process *process)
{
	if (process->window && process->mlx)
		mlx_destroy_window(process->mlx, process->window);
	mlx_destroy_display(process->mlx);
	free(process->mlx);
	exit (EXIT_SUCCESS);
}

void	initialize(t_process *process)
{
	process->mlx = mlx_init();
	if (!process->mlx)
	{
		clean(process);
		exit(EXIT_FAILURE);
	}
	process->window = mlx_new_window(process->mlx, 500, 500, "Fract-ol");
	if (!process->window)
	{
		clean(process);
		exit(EXIT_FAILURE);
	}
}
