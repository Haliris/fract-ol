/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:16:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Create Window
// Parse set and draw on image depending on function
// Handle movement



void	set_color(t_fractole *f, int size_line, int bpp)
{
	int	x;
	int	y;
	int	pixel_index;
	t_palette	*palette;

	y = 0;
	x = 0;
	palette = f->palette;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pixel_index = (y * size_line) + (x * (bpp / 8));
			if (x == y)
				*(int *)(f->img_addr + pixel_index) = palette->core;
			else
				*(int *)(f->img_addr + pixel_index) = palette->background;
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_image(t_fractole *f, char *set)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	(void)set;
	f->img_addr = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	set_color(f, line_bytes, pixel_bits);
	//DRAW LINES
	//UNderstand bpp
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractole	fractole;

	(void)av;
	if (ac != 2)
		return (EXIT_FAILURE);
	initialize(&fractole);
	create_image(&fractole, av[1]);
	mlx_expose_hook(fractole.window, resize_events, &fractole);
	mlx_mouse_hook(fractole.window, mouse_events, &fractole);
 	mlx_key_hook(fractole.window, key_events, &fractole);
 	mlx_loop(fractole.mlx);
	return (EXIT_SUCCESS);
}
