/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:17:05 by archid-           #+#    #+#             */
/*   Updated: 2019/07/16 18:29:35 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "gnl.h"
#include "point.h"

t_pnt		point_init(t_int64 x, t_int64 y, t_int64 z)
{
	t_pnt pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	return (pnt);
}

t_pnt		*get_coords_in_line(char *line, t_uint32 y)
{
	char **splited;
	char **walk;
	t_pnt *cord;
	int i;

	i = 0;
	splited = ft_strsplit(line, ' ');
	cord = ALLOC(t_pnt *, ft_wordcount(line, ' '), sizeof(t_pnt ));
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
