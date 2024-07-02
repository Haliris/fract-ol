/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:12 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 13:39:14 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "math.h"
# define HEIGHT 800
# define WIDTH 800
# define PIXEL_INDEX(x, y, line, bpp) ((y) * (line) + (x) * ((bpp) / 8));
# define MANDELBROT_ESCAPE 2
# define MAX_ITER 500
typedef	struct s_palette
{
	int	background;
	int	outer;
	int	outline;
	int	core;
}	t_palette;

typedef struct s_fractole
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*img_addr;
	t_palette	*palette;
	int			size;
}	t_fractole;

void		clean(t_fractole *fractole);
void		initialize(t_fractole *fractole);
int			key_events(int keycode, t_fractole *fractole);
void		swap_palette(t_fractole *f, char *mode);
int			mouse_events(int mouse_code, t_fractole *fractole);
int			resize_events(int code, t_fractole *fractole);
int			create_color(int r, int g, int b);

void		render_mandelbrot(t_fractole *f, int size_line, int bpp);
#endif
