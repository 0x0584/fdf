/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:54:42 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 18:14:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "fdf.h"
# include "color.h"

typedef struct	s_mlx_environment
{
	void			*mlx;
	void			*win;
	t_fdf_data		*mat;
}				t_env;

typedef enum	e_key_codes
{
	KEY_DEFAULT = -1,
	KEY_ESC = 53,

	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,

	KEY_ZOOM_UP = 69,
	KEY_ZOOM_DOWN = 78,

	KEY_Z_INCR = 35,
	KEY_Z_DECR = 32,

	KEY_ROT_X_UP = 13,
	KEY_ROT_X_DOWN = 7,

	KEY_ROT_Y_UP = 0,
	KEY_ROT_Y_DOWN = 2,

	KEY_ROT_Z_UP = 12,
	KEY_ROT_Z_DOWN = 14,

	KEY_PROJ_PARA = 83,
	KEY_PROJ_ISO = 84
}				t_keycode;

bool			key_is_direc(t_keycode code);
bool			key_is_zoom(t_keycode code);
bool			key_is_z_incr(t_keycode code);
bool			key_is_rot(t_keycode code);
bool			key_is_proj(t_keycode code);

int				key_press(int keycode, void *param);
int				default_color(int color);

#endif
