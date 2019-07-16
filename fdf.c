/*
    fdf.c
    created: July, 16 06:51
*/

#include "fdf.h"

// void		point_dbg(t_pnt_array pnts);

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
		ft_lstpush(&lines, ft_lstnew(str, ft_strlen(str)));
	if (ret < 0)
		ft_lstdel(&lines, line_free);
	return (lines);
}

t_fdf_data	*point_read_fdf(const int fd)
{
	t_plist lines;
	t_plist walk;
	t_fdf_data *fdf;
	t_uint32 i;

	UNLESS_RET(fd >= 0, NULL);
	UNLESS_RET(fdf = ALLOC(t_fdf_data *, 1, sizeof(t_fdf_data)), NULL);
	i = 0;
    lines = file_to_lst(fd);
	fdf->width = ft_wordcount(lines->content, ' ');
	fdf->length = ft_lstlen(lines);
	fdf->base = ALLOC(t_pnt **, fdf->length, sizeof(t_pnt *));
	walk = lines;
	while (walk)
	{
		fdf->base[i] = get_coords_in_line(walk->content, i++);
		walk = walk->next;
	}
    ft_lstdel(&lines, line_free);
	return (fdf);
}