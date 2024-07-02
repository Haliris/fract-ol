/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 18:49:39 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ESC_KEY 65307

// void	update_img(t_fractole *f)
// {

// }

void	do_zoom(t_fractole *f, double dist)
{
	double	r_center;
	double	i_center;

	r_center = f->min_r - f->max_r;
	i_center = f->max_i - f->min_i;
	f->max_r = f->max_r + (r_center - dist * r_center) / 2.0;
	f->min_r = f->max_r + dist * r_center;
	f->min_i = f->min_i + (i_center - dist * i_center) / 2.0;
	f->max_i = f->min_i + dist * i_center;
}

int	key_events(int keycode, t_fractole *fractole)
{
	if (keycode == 65451)
		do_zoom(fractole, 0.10);
	if (keycode == 65453)
		do_zoom(fractole, 10.0);
	if (keycode == ESC_KEY)
		clean(fractole);
	create_image(fractole);
	return (1);
}

void	do_dezoom(t_fractole *fractole, double dist)
{
	(void)dist;
	(void)fractole;
}

int	mouse_events(int mouse_code, t_fractole *fractole)
{
	if (mouse_code == 4)
		do_zoom(fractole, 1.10);
	if (mouse_code == 5)
		do_zoom(fractole, 0.90);
	return (1);
}

int	resize_events(int code, t_fractole fractole)
{
	(void)fractole;
	(void)code;
	return (1);
}
#undef ESC_KEY
