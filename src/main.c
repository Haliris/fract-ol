/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 14:36:39 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Create Window
// Parse set and draw on image depending on function
// Handle movement

void	window_loop(t_process *process)
{

	mlx_key_hook(process->window, key_events, &process);
	mlx_loop(process->mlx);
}



int	main(int ac, char **av)
{
	t_process	*process;

	(void)av;
	if (ac < 2)
		return (EXIT_FAILURE);
	process = initialize();
	window_loop(process);
	return (EXIT_SUCCESS);
}
