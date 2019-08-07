/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:47:30 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:55:29 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color		default_color(int color)
{
	static t_color default_color = WHITE;

	if (color == -1)
		return (default_color);
	default_color = color;
	return (default_color);
}
