/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 23:17:05 by archid-           #+#    #+#             */
/*   Updated: 2019/07/16 00:38:05 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "gnl.h"

#include <stdio.h>

t_pnt		point_init(t_int64 x, t_int64 y, t_int64 z)
{
	t_pnt pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	return (pnt);
}

/* TODO: implement read_fdf */

static void line_free(void *line, size_t size)
{
	if (size)
		free(line);
}

t_plist		file_to_lst(const int fd)
{
	t_plist lines;
	ssize_t ret;
	char *str;

	while ((ret = get_next_line(fd, &str)) > 0)
	{
		/*
		 * if file is
		 *
		 * aaa
		 * bbb
		 * ccc
		 *
		 * the list would be
		 *
		 * aaa -> bbb -> ccc
		 *
		 * then we can get elements from head using ft_lstpeek()
		 */
		ft_lstpush(&lines, ft_lstnew(str, ft_strlen(str)));
	}

	if (ret < 0)
		ft_lstdel(&lines, line_free);

	return (lines);
}

t_pnt_array	*point_read_fdf(const int fd)
{
	t_plist lines;
	t_pnt_array *fdf;
	t_uint32 dims[2];

	UNLESS_RET(fd >= 0, NULL);
	UNLESS_RET(fdf = ALLOC(t_pnt_array *, 1, sizeof(t_pnt_array)), NULL);
	ft_bzero(dims, 2 * sizeof(t_uint32));

	lines = file_to_lst(fd);

	dims[0] = ft_strlen(lines->content);
	dims[1] = ft_lstlen(lines);

	return (fdf);
}

void		point_dbg(t_pnt_array pnts)
{
	t_uint32 i;
	t_uint32 j;

	i = 0;

	while (i < pnts.length)
	{
		j = 0;
		while (j < pnts.width)
		{
			printf("(%ld, ", pnts.base[i][j].x);
			printf(", %ld", pnts.base[i][j].y);
			printf(", %ld) ", pnts.base[i][j].z);
			j++;
		}
		i++;
	}
}
