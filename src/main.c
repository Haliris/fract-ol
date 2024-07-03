/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/03 17:24:45 by jteissie         ###   ########.fr       */
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

void	handle_param_error(int exit_code)
{
	ft_putstr_fd("Expected: ./fractole [set] ", STDERR_FILENO);
	ft_putstr_fd("[Julia real constants] ", STDERR_FILENO);
	ft_putstr_fd("[Julia imaginary constant]\n", STDERR_FILENO);
	exit(exit_code);
}

void	parse_constants(t_fractole *f, int ac, char **av)
{
	f->julia_consts[0] = -1.476;
	f->julia_consts[1] = 0;
	if (ac == 4)
	{
		f->julia_consts[0] = ft_atof(av[2]);
		f->julia_consts[1] = ft_atof(av[3]);
	}
}

void	ft_clear_window(t_fractole *f, int size_line, int bpp)
{
	int	x;
	int	pixel_index;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pixel_index = PIXEL_INDEX(x, y, size_line, bpp);
	 		*(int *)(f->img_addr + pixel_index) = create_color(0, 0, 0);
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_image(t_fractole *f)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;


	f->img_addr = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	ft_clear_window(f, line_bytes, pixel_bits);
	// mlx_destroy_image(f->mlx, f->img);
	// f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
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
	mlx_hook(f->window, DestroyNotify, StructureNotifyMask, &clean_handler, f);
}

int	main(int ac, char **av)
{
	t_fractole	fractole;

	(void)av;
	if (ac < 2 || ac > 4)
		handle_param_error(EXIT_FAILURE);
	initialize(&fractole);
	parse_set(av[1], &fractole);
	parse_constants(&fractole, ac, av);
	set_scale(&fractole);
	init_hooks(&fractole);
	create_image(&fractole);
 	mlx_loop(fractole.mlx);
	return (EXIT_SUCCESS);
}
