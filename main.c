#include "point.h"
#include <mlx.h>

#define OFFSET 200

int main(int argc, char *argv[])
{
	/* t_pnt_array fdf; */
	/* int fd; */

	/* UNLESS_RET(argc == 2, -1); */
	/* UNLESS_RET((fd = open(argv[1], O_RDONLY)) >= 0, -1); */

	/* fdf = point_read_fdf(fd); */
	/* point_dbg(fdf); */

	const t_uint32 length = 3, width = 4;
	t_pnt points[length][width] = {
		{
			{1,0,0},
			{0,0,1},
			{2,3,1},
			{2,3,2},
		},
		{
			{0,1,0},
			{0,1,0},
			{3,2,3},
			{3,4,3},
		},
		{
			{0,0,1},
			{1,0,0},
			{1,3,2},
			{2,3,2},
		},
	};

	void *mlx_id;
	void *win_id;

	t_uint32 i;
	t_uint32 j;

	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id,
							width * OFFSET,
							length * OFFSET,
							"FDF");

	t_pnt origin = {width * OFFSET / 2, length * OFFSET / 2, 0};

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < width)
		{
			printf("%ld, %ld, %ld\n",
				   points[i][j].x,
				   points[i][j].y,
				   points[i][j].z);

			int foo = 100;
			while (foo--)
				mlx_pixel_put(mlx_id, win_id,
							 origin.x + points[i][j].x + foo, origin.y + points[i][j].y + foo,
							  255);
			j++;
		}
		i++;
	}

	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);

	return (0);
}
