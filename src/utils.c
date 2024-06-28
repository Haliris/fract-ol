/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 14:36:16 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean(t_process *process)
{
	if (process->window)
	{
		mlx_destroy_window(process->mlx, process->window);
	}
	free(process->mlx);
	free(process);
	return ;
}

t_process	initialize(void)
{
	t_process	*process;

	process = ft_calloc(1, sizeof(t_process));
	if (!process)
		exit(EXIT_FAILURE);
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
