/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:41 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:26:51 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean(t_fractole *fractole)
{
	if (fractole->img)
		mlx_destroy_image(fractole->mlx, fractole->img);
	if (fractole->window)
		mlx_destroy_window(fractole->mlx, fractole->window);
	if (fractole->palette)
		free(fractole->palette);
	mlx_destroy_display(fractole->mlx);
	free(fractole->mlx);
	exit(EXIT_SUCCESS);
}

void	parse_set(char *set, t_fractole *f)
{
	if (ft_strncmp(set, "mandelbrot", 10) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(set, "julia", 5) == 0)
		f->set = JULIA;
	else if (ft_strncmp(set, "burning", 7) == 0)
		f->set = BURNING;
	else
		handle_param_error(EXIT_FAILURE);
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

void	set_scale(t_fractole *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->max_i = -2.0;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	if (f->set == BURNING)
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = 1.0;
		f->min_i = f->max_i - (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	initialize(t_fractole *f, char **av, int ac)
{
	parse_set(av[1], f);
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(EXIT_FAILURE);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->palette = NULL;
	f->img_addr = NULL;
	f->max_iter = MAX_ITER;
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	swap_palette(f, "default");
	if (!f->img || !f->palette || !f->window)
		exit(clean(f));
	set_scale(f);
	parse_constants(f, ac, av);
}
