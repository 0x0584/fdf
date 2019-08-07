/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:54:42 by archid-           #+#    #+#             */
/*   Updated: 2019/08/08 00:25:02 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "fdf.h"
# include "color.h"
# include "point.h"

typedef struct	s_mlx_environment
{
	void			*mlx;
	void			*win;
	t_fdf_data		*mat;
}				t_env;

int				key_press(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);

#endif
