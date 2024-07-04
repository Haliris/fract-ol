/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 11:18:08 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ESC_KEY 65307

// void	update_img(t_fractole *f)
// {

// }

void	do_zoom(t_fractole *f, double dist, double x, double y)
{
	double	r_center;
	double	i_center;
	double	r_range;
	double	i_range;

	r_center = x;
	i_center = y;
	r_range = (f->max_r - f->min_r) * dist;
	i_range = (f->max_i - f->min_i) * dist;
	f->min_r = r_center - r_range / 2.0;
	f->max_r = r_center + r_range / 2.0;
	f->min_i = i_center - i_range / 2.0;
	f->max_i = i_center + i_range / 2.0;;
}

void	do_move(t_fractole *f, double dist_r, double dist_i)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	f->max_r += dist_r * range_r;
	f->min_r += dist_r * range_r;
	f->max_i += dist_i * range_i;
	f->min_i += dist_i * range_i;
}

void	change_palette(t_fractole *f, int mode)
{
	if (mode == 49)
		swap_palette(f, "default");
	if (mode == 50)
		swap_palette(f, "psychedelic");
	if (mode == 51)
		swap_palette(f, "firestorm");
}

int	key_events(int keycode, t_fractole *fractole)
{
	if (keycode == 49 || keycode == 50 || keycode == 51)
		change_palette(fractole, keycode);
	if (keycode == 65363) //right
		do_move(fractole, 0.1, 0.0);
	if (keycode == 65361) //left
		do_move(fractole, -0.1, 0.0);
	if (keycode == 65362) //up
		do_move(fractole, 0.0, 0.1);
	if (keycode == 65364) //down
		do_move(fractole, 0.0, -0.1);
	if (keycode == 112)
		fractole->max_iter += 5;
	if (keycode == 111 && fractole->max_iter - 5 >= 0)
			fractole->max_iter -= 5;
	if (keycode == ESC_KEY)
		clean(fractole);
	create_image(fractole);
	return (1);
}

int	mouse_events(int mouse_code, int x, int y, t_fractole *f)
{
	double	mouse_r;
	double	mouse_imag;
	mouse_r = f->min_r + (double)x / WIDTH * (f->max_r - f->min_r);
	mouse_imag = f->min_i + (double)y / HEIGHT * (f->max_i - f->min_i);
	if (mouse_code == 4)
		do_zoom(f, 0.95, mouse_r, mouse_imag);
	if (mouse_code == 5)
		do_zoom(f, 1.15, mouse_r, mouse_imag);
	create_image(f);
	return (1);
}

int	clean_handler(t_fractole *fractole)
{
	clean(fractole);
	return (1);
}

int	resize_events(int code, t_fractole fractole)
{
	(void)fractole;
	(void)code;
	return (1);
}
#undef ESC_KEY
