/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:16:49 by archid-           #+#    #+#             */
/*   Updated: 2019/07/16 21:48:53 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_line(void *mlx_id, void *win_id, t_pnt a, t_pnt b)
{
	double delta[3];
	t_int64 y;
	t_int64 x;
	double error;

	delta[0] = b.x - a.x;		/* not zero! */
	delta[1] = b.y - b.y;
	delta[2] = fabs((double)delta[1] / delta[0]);

	printf("------------");
	error = 0.0;
	y = a.y;
	x = a.x;
	while (x < b.x)
	{
		/* point_plot(mlx_id, win_id, (t_pnt){x++, y, 0}); */
		error += delta[2];
		if (error >= 0.5)
		{
			y += delta[1] >= 0 ? 1 : -1;
			error--;
		}
		x++;
	}
}
