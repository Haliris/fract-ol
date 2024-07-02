/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:12 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 18:25:15 by jteissie         ###   ########.fr       */
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
# define MANDELBROT_ESCAPE 4
# define JULIA_ESCAPE 4
# define MAX_ITER 42
# define MANDELBROT 1
# define JULIA 2
typedef	struct s_palette
{
	int	background;
	int	outer_1;
	int	outer_2;
	int	outer_3;
	int	outer_4;
	int	outline_1;
	int	outline_2;
	int outline_3;
	int	core;
}	t_palette;

typedef struct s_fractole
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*img_addr;
	t_palette	*palette;
	double		max_r;
	double		min_r;
	double		max_i;
	double		min_i;
	int			set;
}	t_fractole;

void		clean(t_fractole *fractole);
void		initialize(t_fractole *fractole);
int			key_events(int keycode, t_fractole *fractole);
void		swap_palette(t_fractole *f, char *mode);
int			mouse_events(int mouse_code, t_fractole *fractole);
int			resize_events(int code, t_fractole fractole);
void		set_scale(t_fractole *f);

int			create_color(int r, int g, int b);
void		put_color(t_fractole *f, int pixel_index, int iter);

void		create_image(t_fractole *f);
void		render_mandelbrot(t_fractole *f, int size_line, int bpp);
void		render_julia(t_fractole *f, int size_line, int bpp);
#endif
