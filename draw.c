/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:16:49 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 20:44:31 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <mlx.h>
#include <stdio.h>

void draw_line(void *mlx, void *win, t_pnt3d a, t_pnt3d b)
{
	int x0, x1, y0, y1;

	x0 = a.x;
	x1 = b.x;
	y0 = a.y;
	y1 = b.y;
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    mlx_pixel_put(mlx, win, x0, y0, 0x00FFAA);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

/*void	draw_line(void *mlx_id, void *win_id, t_pnt3d a, t_pnt3d b)
{
	float ex = labs(b.x - a.x);
	float ey = labs(b.y - a.y);
	float dx = 2 * ex;
	float dy = 2 * ey;

	int xincr = 1;
	int yincr = 1;

	int i = 0;
	int Dx = ex;
	int Dy = ey;

	//pour gerer 2 posibilite ds chaque cas
	if (a.x > b.x)
		xincr = -1;
	if (a.y > b.y)
		yincr = -1;
	if(a.x == b.x)
		xincr = 0;
	if(a.y == b.y)
		yincr = 0;
	float y = a.y;

	if(Dx < Dy) //1er cas
	{
		while (i <= Dy)
		{
			mlx_pixel_put(mlx_id, win_id, a.x, a.y, 0x00FFAA);
			i++;
			a.x = a.x + xincr; 
			ex = ex - dy;
			if(ex < 0)
			{
				a.y = a.y + yincr;
				ex = ex + dx;
			}
		//printf ("\n%ld %ld",a.x,a.y);
		}
	}
	else  //2eme cas (Dx >= Dy)
	{
		while (i <= Dx)
		{
			mlx_pixel_put(mlx_id, win_id,a.x,a.y, 0x00FFAA);
			i++;
			a.y = a.y + yincr;
			ey = ey - dx;
			if(ey < 0)
			{
				a.x = a.x + xincr;
				ey = ey + dy;
			}
		//printf ("\n%ld %ld",a.x,a.y);
		}
	}
}
*/