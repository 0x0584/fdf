/*
    fdf.c
    created: July, 16 06:51
*/
#include "gnl.h"
#include "fdf.h"
#include "gnl.h"
#include <stdio.h>

// void		point_dbg(t_pnt_array pnts);

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

	while ((ret = get_next_line(fd, &str)) > 0)
		ft_lstpush(&lines, ft_lstnew(str, ft_strlen(str) + 1)); // segfault prblm is fixed (missing +1)
	if (ret < 0)
		ft_lstdel(&lines, lstdel_linefree);
	return (lines);
}

/*
   IDEA:

   you have to implement a line equation so you need a new data
   structure of the line.

   struct line {
		t_pnt3d a, b;
   }

   next you have to implem line_get_xy(line, x) and line_get_yx(line, y)
   and then, compute the distance between a and b, and then check y each time
   whether we're less than half or not. if so print (y + 1), or else print y
*/

t_fdf_data		*fdf_read(const int fd)
{
	t_plist			lst[2]; // i dont know why table of 2 dim ?
	t_fdf_data		*fdf;
	t_uint32		y_axis;

	puts("in read_fdf");
	UNLESS_RET(fd >= 0, NULL);
	UNLESS_RET(fdf = ALLOC(t_fdf_data *, 1, sizeof(t_fdf_data)), NULL);
	puts("after alloc");
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
