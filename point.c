/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:17:05 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 01:35:45 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "gnl.h"
#include "point.h"

t_pnt2d		point_2d_init(t_int64 x, t_int64 y)
{
	t_pnt2d pnt;

	pnt.x = x;
	pnt.y = y;
	return (pnt);
}


t_pnt3d		point_3d_init(t_int64 x, t_int64 y, t_int64 z)
{
	t_pnt3d pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	return (pnt);
}

t_pnt3d		*get_coords_in_line(char *line, t_uint32 y)
{
	char **splited;
	char **walk;
	t_pnt3d *cord;
	int i;

	i = 0;
	splited = ft_strsplit(line, ' ');
	cord = ALLOC(t_pnt3d *, ft_wordcount(line, ' '), sizeof(t_pnt3d));
	walk = splited;
	while (*walk)
	{
		cord[i].x = i;
		cord[i].y = y;
		cord[i++].z = ft_atoi(*walk++);
	}
	walk = splited;
	while (*walk)
		ft_strdel(walk++);
	ft_strdel(splited);
	return (cord);
}

void		point_plot(void *mlx_id, void *win_id, t_pnt2d point)
{
	mlx_pixel_put(mlx_id, win_id, point.x, point.y, 200);
}
