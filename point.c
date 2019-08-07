/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:17:05 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:21:52 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt3d		point_3d_init(t_int64 x, t_int64 y, t_int64 z, t_color color)
{
	t_pnt3d pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	pnt.color = color;
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
		cord[i].z = ft_atoi(ft_strcdup(*walk,','));
		cord[i++].color = (ft_strchr(*walk,',') != NULL) ?
			(ft_atoi_base(ft_strchr(*walk,',') + 3,"0123456789abcdef")) : WHITE;
		walk++;
	}
	walk = splited;
	while (*walk)
		ft_strdel(walk++);
	ft_strdel(splited);
	return (cord);
}

t_pnt3d			**point_alloc_array(t_uint32 length, t_uint32 width)
{
	t_pnt3d			**array;
	t_uint32		i;

	i = 0;
	array = (t_pnt3d **)malloc(sizeof(t_pnt3d *) * length);
	while(i < length)
	{
		array[i] = (t_pnt3d *)malloc(sizeof(t_pnt3d) * width);
		i++;
	}
	return (array);
}


void	point_free_array(t_pnt3d **array, t_uint32 length)
{
	t_uint32 i;

	i = 0;
	while (i < length)
		free(array[i++]);
	free(array);
}
