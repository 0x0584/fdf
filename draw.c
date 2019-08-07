/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:16:49 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 18:33:51 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void draw_line(t_env *env, t_pnt3d a, t_pnt3d b, t_color color)
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
    	mlx_pixel_put(env->mlx, env->win, a.x, a.y, color);
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

void	draw_color_square(t_env *env, t_pnt3d head, t_uint32 size)
{
	t_pnt3d		next;
	t_uint32	i;

	i = 0;
	next.x = head.x + size;
	next.y = head.y;
	while (i++ <= size)
	{
		draw_line(env, head ,next, head.color);
		next.y++;
		head.y++;
	}
}

void	draw_map(t_env *env, t_color color, t_pnt3d **redf)
{
	t_uint32 i = 0;
	t_uint32 j;

	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			if (j != (env->mat->width - 1))
				draw_line(env, redf[i][j],redf[i][j + 1], color);
			if(i != (env->mat->length - 1))
				draw_line(env, redf[i][j],redf[i + 1][j], color);
			j++;
		}
		i++;
	}
}

void	draw_edge(t_env *env)
{
	int i;

	i = 0;
	while (i < 140)
	{
		draw_line(env,
				  (t_pnt3d){0,860+i,0,BLACK},
				  (t_pnt3d){2000, 860+i, 0, BLACK}, BLACK);
		i++;
	}
	t_pnt3d points[] = {
		{.y = 900, .color = FIRE_BRICK, .x = 70},
		{.y = 900, .color = DARK_GREEN, .x = 110},
		{.y = 900, .color = COLOR_BLUE, .x = 150},
	};
	mlx_string_put(env->mlx, env->win, 150 + 70, 905, LIGHT_GRAY,
				   "Zoom: +/- | Z-axis: u/p | Translation: UP/DOWN "
				   "LEFT/RIGHT | RotationX: W/X | RotationY: A/D | "
				   "RotationZ: Q/E | Projection: Parallel(1)/isometrique(2) ");
	mlx_string_put(env->mlx, env->win, 94, 870, LIGHT_GRAY, "Colors: ");
	draw_color_square(env, points[0], 30);
	draw_color_square(env, points[1], 30);
	draw_color_square(env, points[2], 30);
}
