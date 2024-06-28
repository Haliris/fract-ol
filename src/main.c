/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:29:40 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 14:12:11 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"
#include "math.h"

// Mandelbrot Zn+1 = Zn2 + C
// Julia z = z2 + c

// Create Window
// Parse set and draw on image depending on function
// Handle movement
void	window_loop(void *mlx)
{
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*window;

	(void)av;
	if (ac < 2)
		return (EXIT_FAILURE);
	mlx = mlx_init();
	if (!mlx)
		return (EXIT_FAILURE);
	window = mlx_new_window(mlx, 500, 500, "Fract-ol test");
	if (!window)
	{
		//catch the error, free init?
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	free(mlx);
	return (EXIT_SUCCESS);
}
