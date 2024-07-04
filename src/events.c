/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:28:30 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	f->max_i = i_center + i_range / 2.0;
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

int	key_events(int keycode, t_fractole *fractole)
{
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3)
		change_palette(fractole, keycode);
	if (keycode == ARROW_RIGHT)
		do_move(fractole, 0.1, 0.0);
	if (keycode == ARROW_LEFT)
		do_move(fractole, -0.1, 0.0);
	if (keycode == ARROW_UP)
		do_move(fractole, 0.0, 0.1);
	if (keycode == ARROW_DOWN)
		do_move(fractole, 0.0, -0.1);
	if (keycode == KEY_P)
		fractole->max_iter += 5;
	if (keycode == KEY_O && fractole->max_iter - 5 >= 0)
			fractole->max_iter -= 5;
	if (keycode == KEY_ESC)
		exit(clean(fractole));
	create_image(fractole);
	return (1);
}

int	mouse_events(int mouse_code, int x, int y, t_fractole *f)
{
	double	mouse_r;
	double	mouse_imag;

	mouse_r = f->min_r + (double)x / WIDTH * (f->max_r - f->min_r);
	mouse_imag = f->min_i + (double)y / HEIGHT * (f->max_i - f->min_i);
	if (mouse_code == MOUSE_DOWN)
		do_zoom(f, 0.95, mouse_r, mouse_imag);
	if (mouse_code == MOUSE_UP)
		do_zoom(f, 1.15, mouse_r, mouse_imag);
	create_image(f);
	return (1);
}

void	change_palette(t_fractole *f, int mode)
{
	if (mode == KEY_1)
		swap_palette(f, "default");
	if (mode == KEY_2)
		swap_palette(f, "psychedelic");
	if (mode == KEY_3)
		swap_palette(f, "firestorm");
}
