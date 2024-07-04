/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:12 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/04 13:40:32 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "keys.h"
# include "libft.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGHT 800
# define WIDTH 800
# define PIXEL_INDEX(x, y, line, bpp) ((y) * (line) + (x) * ((bpp) / 8));
# define MANDELBROT_ESCAPE 4
# define JULIA_ESCAPE 4
# define BURNING_ESCAPE 4
# define MAX_ITER 40
# define MANDELBROT 1
# define JULIA 2
# define BURNING 3

typedef struct s_palette
{
	int	core;
	int	out;
	int	in;
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
	double		max_iter;
	double		julia_consts[2];
}	t_fractole;

int			clean(t_fractole *fractole);
void		initialize(t_fractole *fractole, char **av, int ac);
void		handle_param_error(int exit_code);
double		ft_atof(char *nptr);
int			key_events(int keycode, t_fractole *fractole);
void		swap_palette(t_fractole *f, char *mode);
t_palette	*create_palette(char *mode);
void		change_palette(t_fractole *f, int mode);

int			mouse_events(int mouse_code, int x, int y, t_fractole *fractole);
void		ft_clear_window(t_fractole *f, int size_line, int bpp);

int			create_color(int r, int g, int b);
void		put_color(t_fractole *f, int pixel_index, double iter);

void		create_image(t_fractole *f);
void		render_mandelbrot(t_fractole *f, int size_line, int bpp);
void		render_julia(t_fractole *f, int size_line, int bpp);
void		render_burning(t_fractole *f, int size_line, int bpp);
#endif
