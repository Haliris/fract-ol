/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:12 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:49 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "math.h"

// typedef	struct	s_image
// {
// 	char	*addr;
// 	int		bits_per_pix;
// 	int		size_line;
// }	t_image;

typedef struct s_process
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_addr;
	int		size;
}	t_process;

void		clean(t_process *process);
void		initialize(t_process *process);
int			key_events(int keycode, t_process *process);
int			mouse_events(int mouse_code, t_process *process);
int			resize_events(int code, t_process *process);

#endif