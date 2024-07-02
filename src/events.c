/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:05:01 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_fractole *fractole)
{
	if (keycode == 65307)
		clean(fractole);
	return (1);
}

int	mouse_events(int mouse_code, t_fractole *fractole)
{
	(void)fractole;
	(void)mouse_code;
	return (1);
}

int	resize_events(int code, t_fractole *fractole)
{
	(void)fractole;
	(void)code;
	return (1);
}
