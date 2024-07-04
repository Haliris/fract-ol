/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:54:53 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 11:58:20 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_palette(t_fractole *f, int mode)
{
	if (mode == KEY_1)
		swap_palette(f, "default");
	if (mode == KEY_2)
		swap_palette(f, "psychedelic");
	if (mode == KEY_3)
		swap_palette(f, "firestorm");
}
