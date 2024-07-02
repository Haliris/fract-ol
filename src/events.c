/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 17:38:53 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ESC_KEY 65307

int	key_events(int keycode, t_fractole *fractole)
{
	if (keycode == ESC_KEY)
		clean(fractole);
	return (1);
}

void	do_zoom(t_fractole *fractole, double dist)
{
	(void)dist;
	(void)fractole;
}

void	do_dezoom(t_fractole *fractole, double dist)
{
	(void)dist;
	(void)fractole;
}

int	mouse_events(int mouse_code, t_fractole *fractole)
{
	(void)fractole;
	if (mouse_code == 4)
		do_zoom(fractole, 2);
	if (mouse_code == 5)
		do_dezoom(fractole, 2);
	return (1);
}

int	resize_events(int code, t_fractole *fractole)
{
	(void)fractole;
	(void)code;
	return (1);
}
#undef ESC_KEY
