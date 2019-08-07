/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 06:51:22 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 22:04:50 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		lstdel_linefree(void *line, size_t size)
{
	if (size)
		free(line);
}

static t_plist	file_to_lst(const int fd)
{
	t_plist			lines;
	ssize_t			ret;
	char			*str;

	lines = NULL;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		ft_lstpush(&lines, ft_lstnew(str, ft_strlen(str) + 1));
		ft_strdel(&str);
	}
	if (ret < 0)
		ft_lstdel(&lines, lstdel_linefree);
	return (lines);
}

t_fdf_data		*fdf_read(const int fd)
{
	t_plist			lst[2];
	t_fdf_data		*fdf;
	t_uint32		y_axis;

	UNLESS_RET(fd >= 0, NULL);
	UNLESS_RET(fdf = ALLOC(t_fdf_data *, 1, sizeof(t_fdf_data)), NULL);
	lst[0] = file_to_lst(fd);
	fdf->width = ft_wordcount(lst[0]->content, ' ');
	fdf->length = ft_lstlen(lst[0]);
	fdf->base = ALLOC(t_pnt3d **, fdf->length, sizeof(t_pnt3d *));
	y_axis = 0;
	lst[1] = lst[0];
	while (lst[1])
	{
		fdf->base[y_axis] = get_coords_in_line(lst[1]->content, y_axis);
		lst[1] = lst[1]->next;
		y_axis++;
	}
	ft_lstdel(&lst[0], lstdel_linefree);
	return (fdf);
}

void			fdf_free(t_fdf_data **fdf)
{
	t_uint32		len;

	len = 0;
	while (len < (*fdf)->width)
		free((*fdf)->base[len]);
	free((*fdf)->base);
	free(*fdf);
	*fdf = NULL;
}

t_info			*get_fdf_info(void)
{
	static t_info info;

	info.length = WIN_LENGTH;
	info.width = WIN_WIDTH;
	info.spacing = INIT_SPACING;
	info.z_incr = INIT_Z_INCR;
	info.verti = INIT_VERTI;
	info.horiz = INIT_HORIZ;
	info.angle[ROT_X] = INIT_ANGLE_X;
	info.angle[ROT_Y] = INIT_ANGLE_Y;
	info.angle[ROT_Z] = INIT_ANGLE_Z;
	info.proj_type = INIT_PROJECTION_TYPE;
	return (&info);
}
