/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 16:09:27 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Parse set and draw on image depending on function
// Handle movement
//Pre-calculate movements




void	create_image(t_fractole *f, char *set)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	f->img_addr = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	if (ft_strncmp(set, "mandelbrot", 10) == 0)
		render_mandelbrot(f, line_bytes, pixel_bits);
	else if (ft_strncmp(set, "julia", 5) == 0)
		render_julia(f, line_bytes, pixel_bits);
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
	create_image(&fractole, av[1]);
	mlx_expose_hook(fractole.window, resize_events, &fractole);
	mlx_mouse_hook(fractole.window, mouse_events, &fractole);
 	mlx_key_hook(fractole.window, key_events, &fractole);
 	mlx_loop(fractole.mlx);
	return (EXIT_SUCCESS);
}
