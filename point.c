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

#include "point.h"
#include "gnl.h"
#include <mlx.h>

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
	t_plist walk;
	t_pnt_array *fdf;
	t_uint32 i;

	UNLESS_RET(fd >= 0, NULL);
	UNLESS_RET(fdf = ALLOC(t_pnt_array *, 1, sizeof(t_pnt_array)), NULL);

	lines = file_to_lst(fd);

	fdf->width = ft_strlen(lines->content);
	fdf->length = ft_lstlen(lines);

	i = 0;
	fdf->base = ALLOC(t_pnt **, fdf->length, sizeof(t_pnt *));
	walk = lines;
	while (walk)
	{
		/* fdf->base[i] = get_coords_in_line(walk->content, i); */
		walk = walk->next;
		i++;
	}
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

#define OFFSET 200

void		plot_all_point(t_pnt_array *pnts)
{
	void *mlx_id;
	void *win_id;

	t_uint32 i;
	t_uint32 j;

	/* mlx_id = mlx_init(); */
	/* win_id = mlx_new_window(mlx_id, */
	/* 						pnts->width * OFFSET, */
	/* 						pnts->length * OFFSET, */
	/* 						"FDF"); */
	i = 0;
	while (i < pnts->length)
	{
		j = 0;
		while (j < pnts->width)
		{
			printf("%ld, %ld, %ld\n",
				   pnts->base[i][j].x,
				   pnts->base[i][j].y,
				   pnts->base[i][j].z);

			/*
			mlx_pixel_put(mlx_id, win_id,
						  pnts->base[i][j].x, pnts->base[i][j].y,
						  120);
			*/
			j++;
		}
		i++;
	}
	/* mlx_loop(mlx_id); */
	/* mlx_clear_window(mlx_id, win_id); */
	/* mlx_destroy_window(mlx_id, win_id); */
}

t_pnt		*get_coords_in_line(char *line, t_uint32 y)
{
	char **splited;
	char **walk;				/* to keep the original safe */
	t_pnt *cord;
	int i;

	i = 0;
	splited = ft_strsplit(line, ' '); // to be free'd
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
