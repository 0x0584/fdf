/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:16:49 by archid-           #+#    #+#             */
/*   Updated: 2019/08/06 20:29:18 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <mlx.h>
#include <stdio.h>

void draw_line(void *mlx, void *win, t_pnt3d a, t_pnt3d b ,int color)
{
  	int dx;
  	int dy;
  	int sx;
  	int sy;
  	int err;
	int e2;

	dx = labs(b.x - a.x);
	dy = labs(b.y - a.y);
	sx = a.x < b.x ? 1 : -1;
	sy = a.y < b.y ? 1 : -1;
	err = (dx > dy ? dx : -dy)/2;

  	while(1)
	{
    	mlx_pixel_put(mlx, win, a.x, a.y, color);
    	if (a.x==b.x && a.y==b.y)
			break;
	    e2 = err;
   		if (e2 > -dx)
		{
			err -= dy;
			a.x += sx;
		}
	    if (e2 < dy)
		{
			err += dx;
			a.y += sy;
		}
  	}
}
