/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/03 14:31:27 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Parse set and draw on image depending on function
// Handle movement
//Pre-calculate movements

void	parse_set(char *set, t_fractole *f)
{
	if (ft_strncmp(set, "mandelbrot", 10) == 0)
		f->set = MANDELBROT;
	if (ft_strncmp(set, "julia", 5) == 0)
		f->set = JULIA;
	if (ft_strncmp(set, "burning", 7) == 0)
		f->set = BURNING;
}

#include <stdio.h>

void	create_image(t_fractole *f)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	mlx_clear_window(f->mlx, f->window);
	f->img_addr = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	if (f->set == MANDELBROT)
		render_mandelbrot(f, line_bytes, pixel_bits);
	else if (f->set == JULIA)
		render_julia(f, line_bytes, pixel_bits);
	else if (f->set == BURNING)
		render_burning(f, line_bytes, pixel_bits);
	else
		return ;
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractole	fractole;

	(void)av;
	if (ac != 2)
		return (EXIT_FAILURE);
	initialize(&fractole);
	parse_set(av[1], &fractole);
	set_scale(&fractole);
	create_image(&fractole);
	mlx_expose_hook(fractole.window, resize_events, &fractole);
	mlx_mouse_hook(fractole.window, mouse_events, &fractole);
 	mlx_key_hook(fractole.window, key_events, &fractole);
 	mlx_loop(fractole.mlx);
	return (EXIT_SUCCESS);
}
