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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_color(t_process *p, int size_line, int bpp)
{
	int	x;
	int	y;
	int	pixel_index;
	int	color;

	color = (255 << 16) | (165 << 8) | 0; //Orange 
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pixel_index = (y * size_line) + (x * (bpp / 8));
			*(int *)(p->img_addr + pixel_index) = color;
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_image(t_process *p, char *set)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	(void)set;
	p->img_addr = mlx_get_data_addr(p->img, &pixel_bits, &line_bytes, &endian);
	set_color(p, line_bytes, pixel_bits);
	//DRAW LINES
	//UNderstand bpp
	mlx_put_image_to_window(p->mlx, p->window, p->img, 0, 0);
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
