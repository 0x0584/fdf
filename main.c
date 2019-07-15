#include "point.h"

int main(int argc, char *argv[])
{
	t_pnt_array fdf;
	int fd;

	UNLESS_RET(argc == 2, -1);
	UNLESS_RET((fd = open(argv[1], O_RDONLY)) >= 0, -1);

	fdf = point_read_fdf(fd);
	point_dbg(fdf);

	return (0);
}
