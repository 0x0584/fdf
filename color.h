/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:20:08 by archid-           #+#    #+#             */
/*   Updated: 2019/08/08 00:41:59 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COUNT_COLORS_CHOICE 9

typedef enum	e_color
{
	FIRE_BRICK = 0xB22222,
	DIM_GRAY = 0x696969,
	LIGHT_GRAY = 0xD3D3D3,
	DARK_GREEN = 0x006400,
	COLOR_BLUE = 0x0000FF,
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,

	LIGHT_GREEN = 0x9DCCB9,
	CARAMELLO = 0xCC8B56,
	ORANGINA = 0XFCA326,
	PURPLE_HAZE = 0x9B40AA,
	PINKY = 0XFFBAE9,
	CLOUDY_MORNING = 0xCADBE6
}				t_color;

t_color		set_default_color(int color);

#endif
