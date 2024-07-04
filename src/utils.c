/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:46:21 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:38:28 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	add_decimals(double *result, char *nptr)
{
	int		i;
	double	magnitude;

	magnitude = 10.0;
	i = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		*result = *result + ((nptr[i] - '0') / magnitude);
		magnitude *= 10.0;
		i++;
	}
}

double	ft_atof(char *nptr)
{
	int		i;
	double	result;
	int		minus;

	i = 0;
	result = 0;
	minus = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i++] == '.')
		add_decimals(&result, &nptr[i]);
	if (minus)
		result *= -1;
	return (result);
}

void	handle_param_error(int exit_code)
{
	ft_putstr_fd("Expected: [mandelbrot/julia/burning] ", STDERR_FILENO);
	ft_putstr_fd("[Julia real constant] ", STDERR_FILENO);
	ft_putstr_fd("[Julia imaginary constant]\n", STDERR_FILENO);
	exit(exit_code);
}
