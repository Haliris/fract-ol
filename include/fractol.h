/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:12 by jteissie          #+#    #+#             */
/*   Updated: 2024/07/02 11:08:31 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "math.h"
# define HEIGHT 800
# define WIDTH 800

// typedef	struct	s_image
// {
// 	char	*addr;
// 	int		bits_per_pix;
// 	int		size_line;
// }	t_image;

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
int			create_trgb(int t, int r, int g, int b);
void		initialize(t_fractole *fractole);
int			key_events(int keycode, t_fractole *fractole);
int			mouse_events(int mouse_code, t_fractole *fractole);
int			resize_events(int code, t_fractole *fractole);
int			create_color(int r, int g, int b);

#endif
