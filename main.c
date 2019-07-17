/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:40 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "fdf.h"
#include "draw.h"

#define OFFSET 100
#define COLOR_RED 0xff5050
#define COLOR_WHITE 0x303030

void	do_draw_line(void *mlx_id, void *win_id, t_pnt2d origin, t_pnt2d a, t_pnt2d b)
{
	int foo = 40;

	while (foo--)
		mlx_pixel_put(mlx_id, win_id,
						a.x + origin.x + foo, a.y + origin.y + foo,
						COLOR_RED);
	foo = 25;
	while (foo--)
		mlx_pixel_put(mlx_id, win_id,
						b.x + origin.x + foo, b.y + origin.y + foo,
						COLOR_WHITE);
}


void	do_mlx_test(void)
{
	const t_uint32 length = 3, width = 4;
	t_pnt2d points[length][width] = {
		{{1,0}, {0,0}, {2,3}, {2,3},},
		{{0,1}, {0,1}, {3,2}, {3,4},},
		{{0,0}, {1,0}, {1,3}, {2,3},},
	};

	void *mlx_id;
	void *win_id;

	t_pnt2d index = {0,0};
	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id,
							width * OFFSET,
							length * OFFSET,
							"FDF");

	t_pnt2d origin = {width * OFFSET / 2, length * OFFSET / 2};

	index.y = 0;
	while (index.y < length)
	{
		index.x = 0;
		while (index.x < width)
		{
			printf("%ld, %ld\n", points[index.y][index.x].x,
									points[index.y][index.x].y);
			int foo = 100;
			while (foo--)
				mlx_pixel_put(mlx_id, win_id,
							  origin.x + points[index.y][index.x].x + foo * 2 ,
							  origin.y + points[index.y][index.x].y + foo * 2,
							  255);
			index.x++;
		}
		index.y++;
	}

	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);

}

/*
void	do_read_fdf_test(int argc, char**argv)
{
	t_fdf_data *fdf;
	int fd;

	if (argc != 2 || !((fd = open(argv[1], O_RDONLY)) >= 0))
		return ;
	fdf = point_read_fdf(fd);
	point_dbg(*fdf);
}
*/

void	do_get_coords_test(void)
{
	char *str = "10 20 10 -2";
	const int width = ft_wordcount(str, ' '), n_tests = 5;
	t_uint16 i = 0, j = 0;
	t_pnt3d *pnts = NULL;

	while (i < n_tests)
	{
		j = 0;
		printf("----- OOOOO ------\n");
		pnts = get_coords_in_line(str, i++);
		printf("----- //// ------\n");
		while (j < width)
		{
			/* the cast is because printf returns an int, we don't want that! */
			(void)printf("(x:%ld, y:%ld, z:%ld) ",
						 pnts[j].x, pnts[j].y, pnts[j].z);
			j++;
		}
		(void)printf("\n");
		j = 0;
		free(pnts);
		printf("------ %d ------\n", i);
	}
	printf("----- ^^^ -------");
}

const int win_length = 700, win_width = 700;

int main(int argc, char *argv[])
{
	/* do_read_fdf_test(); */
	/* do_mlx_test(); */

	void *mlx_id, *win_id;
	t_pnt2d head =  {10, -10}, tail = {50, 35},
		origin = {win_width / 2, win_length / 2};

	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, win_length, win_width, "FDF");

	do_get_coords_test();
	do_draw_line(mlx_id, win_id, origin, head, tail);

	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);

	return (0);
}
