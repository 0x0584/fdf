/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:47:30 by archid-           #+#    #+#             */
/*   Updated: 2019/08/08 00:45:07 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "point.h"

t_color		set_default_color(int color)
{
	static t_color set_default_color = WHITE;

	if (color == -1)
		return (set_default_color);
	set_default_color = color;
	return (set_default_color);
}

t_pnt3d		*get_default_colors(void)
{
	static t_pnt3d	points[] = {
		{.y = 810 + 50, .color = FIRE_BRICK, .x = 70},
		{.y = 810 + 50, .color = DARK_GREEN, .x = 110},
		{.y = 810 + 50, .color = COLOR_BLUE, .x = 150},
		{.y = 850 + 50, .color = CLOUDY_MORNING, .x = 70},
		{.y = 850 + 50, .color = ORANGINA, .x = 110},
		{.y = 850 + 50, .color = PINKY, .x = 150},
		{.y = 890 + 50, .color = PURPLE_HAZE, .x = 70},
		{.y = 890 + 50, .color = LIGHT_GREEN, .x = 110},
		{.y = 890 + 50, .color = CARAMELLO, .x = 150},
	};

	return (points);
}
