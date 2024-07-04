/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:42:53 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 16:09:14 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interpolate_red(int color1, int color2, double t)
{
	int	r1;
	int	r2;

	r1 = (color1 >> 16) & 0xFF;
	r2 = (color2 >> 16) & 0xFF;
	return ((int)(r1 + (r2 - r1) * t));
}

int	interpolate_green(int color1, int color2, double t)
{
	int	g1;
	int	g2;

	g1 = (color1 >> 8) & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	return ((int)(g1 + (g2 - g1) * t));
}

int	interpolate_blue(int color1, int color2, double t)
{
	int	b1;
	int	b2;

	b1 = (color1) & 0xFF;
	b2 = (color2) & 0xFF;
	return ((int)(b1 + (b2 - b1) * t));
}

int	interpolate_color(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = interpolate_red(color1, color2, t);
	g = interpolate_green(color1, color2, t);
	b = interpolate_blue(color1, color2, t);
	return (create_color(r, g, b));
}
