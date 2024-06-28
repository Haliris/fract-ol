/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:51:23 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 15:51:33 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_process *process)
{
	if (keycode == 65307)
		clean(process);
	return (1);
}

int	mouse_events(int mouse_code, t_process *process)
{
	(void)process;
	(void)mouse_code;
	return (1);
}

int	resize_events(int code, t_process *process)
{
	(void)process;
	(void)code;
	return (1);
}