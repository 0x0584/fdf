/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:16:49 by archid-           #+#    #+#             */
/*   Updated: 2019/08/08 00:45:49 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_line(t_env *env, t_pnt3d a, t_pnt3d b, t_color color)
{
	t_int64 delta[2];
	t_int64 sdelta[2];
	t_int64 err[2];

	delta[0] = labs(b.x - a.x);
	delta[1] = labs(b.y - a.y);
	sdelta[0] = a.x < b.x ? 1 : -1;
	sdelta[1] = a.y < b.y ? 1 : -1;
	err[0] = (delta[0] > delta[1] ? delta[0] : -delta[1]) / 2;
	while (true)
	{
		mlx_pixel_put(env->mlx, env->win, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		if ((err[1] = err[0]) > -delta[0])
		{
			err[0] -= delta[1];
			a.x += sdelta[0];
		}
		if (err[1] < delta[1])
		{
			err[0] += delta[0];
			a.y += sdelta[1];
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
		draw_line(env, head, next, head.color);
		next.y++;
		head.y++;
	}
}

void	draw_map(t_env *env, t_color color, t_pnt3d **redf)
{
	t_uint32 i;
	t_uint32 j;

	i = 0;
	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			if (j != (env->mat->width - 1))
				draw_line(env, redf[i][j], redf[i][j + 1], color);
			if (i != (env->mat->length - 1))
				draw_line(env, redf[i][j], redf[i + 1][j], color);
			j++;
		}
		i++;
	}
}

void	draw_edge(t_env *env)
{
	t_int16			i;
	static t_pnt3d	*points = NULL;

	i = 0;
	if (points == NULL)
		points = get_default_colors();
	while (i < 140)
	{
		draw_line(env,
					(t_pnt3d){0, 860 + i, 0, BLACK},
					(t_pnt3d){2000, 860 + i, 0, BLACK}, BLACK);
		i++;
	}
	mlx_string_put(env->mlx, env->win, 150 + 70, 905, LIGHT_GRAY,
					"Zoom: +/- | Z-axis: u/p | Translation: UP/DOWN "
					"LEFT/RIGHT | RotationX: W/X | RotationY: A/D | "
					"RotationZ: Q/E | Projection: Parallel(1)/isometrique(2)");
	i = 0;
	while (i < COUNT_COLORS_CHOICE)
		draw_color_square(env, points[i++], 30);
}
