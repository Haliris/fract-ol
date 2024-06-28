/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 15:26:29 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Create Window
// Parse set and draw on image depending on function
// Handle movement

int	key_events(int keycode, t_process *process)
{
	if (keycode == 65307)
		clean(process);
	return 1;
}

int	main(int ac, char **av)
{
	t_process	process;

	(void)av;
	if (ac < 2)
		return (EXIT_FAILURE);
	initialize(&process);
 	mlx_key_hook(process.window, key_events, &process);
 	mlx_loop(process.mlx);
	return (EXIT_SUCCESS);
}
