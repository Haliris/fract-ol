/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 16:49:08 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Create Window
// Parse set and draw on image depending on function
// Handle movement

void	set_color(t_process *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 700)
	{
		while (x < 700)
		{
			p->img_addr[x + y] = 0x000000BB;
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_image(t_process *p, char *set)
{
	(void)set;
	set_color(p);
	mlx_put_image_to_window(p->mlx, p->window, p->img, p->size, p->size);

}

int	main(int ac, char **av)
{
	t_process	process;

	(void)av;
	if (ac != 2)
		return (EXIT_FAILURE);
	initialize(&process);
	create_image(&process, av[1]);
	mlx_expose_hook(process.window, resize_events, &process);
	mlx_mouse_hook(process.window, mouse_events, &process);
 	mlx_key_hook(process.window, key_events, &process);
 	mlx_loop(process.mlx);
	return (EXIT_SUCCESS);
}
