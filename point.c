#include "point.h"
#include <stdio.h>

void		point_init(t_pnt *pnt, t_int64 x, t_int64 y, t_int64 z)
{
	if (pnt != NULL)
	{
		pnt->x = x;
		pnt->y = y;
		pnt->z = z;
	}
}

/* TODO: implement read_fdf */

t_pnt_array	point_read_fdf(const int fd)
{
	t_pnt_array fdf = {NULL, 0, 0};
	if (fd)
		;
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
