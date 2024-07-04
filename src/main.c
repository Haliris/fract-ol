/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:33:54 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_fractole *f)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	f->img_addr = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	ft_clear_window(f, line_bytes, pixel_bits);
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

void	init_hooks(t_fractole *f)
{
	mlx_hook(f->window, KeyRelease, KeyReleaseMask, &key_events, f);
	mlx_hook(f->window, ButtonPress, ButtonPressMask, &mouse_events, f);
	mlx_hook(f->window, DestroyNotify, StructureNotifyMask, &clean, f);
}

int	main(int ac, char **av)
{
	t_fractole	fractole;

	(void)av;
	if (ac < 2 || ac > 4)
		handle_param_error(EXIT_FAILURE);
	initialize(&fractole, av, ac);
	create_image(&fractole);
	init_hooks(&fractole);
	mlx_loop(fractole.mlx);
	return (EXIT_SUCCESS);
}
