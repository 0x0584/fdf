/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:46:54 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:47:08 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"


bool			key_is_direc(t_keycode code)
{
	return (code == KEY_LEFT || code == KEY_RIGHT
			|| code == KEY_UP || code == KEY_DOWN);
}

bool			key_is_zoom(t_keycode code)
{
	return (code == KEY_ZOOM_UP || code == KEY_ZOOM_DOWN);
}

bool			key_is_z_incr(t_keycode code)
{
	return (code == KEY_Z_INCR || code == KEY_Z_DECR);
}

bool			key_is_rot(t_keycode code)
{
	return (code == KEY_ROT_X_UP || code == KEY_ROT_X_DOWN
			|| code == KEY_ROT_Y_UP || code == KEY_ROT_Y_DOWN
			|| code == KEY_ROT_Z_UP || code == KEY_ROT_Z_DOWN);
}

bool			key_is_proj(t_keycode code)
{
	return (code == KEY_PROJ_ISO || code == KEY_PROJ_PARA);
}
