/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/07/16 18:41:22 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "fdf.h"

#define OFFSET 200

void	do_mlx_test(void)
{
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
	t_pnt *pnts = NULL;

	while (i < n_tests)
	{
		j = 0;
		pnts = get_coords_in_line(str, i++);
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
	}

}

int main(int argc, char *argv[])
{
	/* do_read_fdf_test(); */
	/* do_mlx_test(); */

	do_get_coords_test();

	return (0);
}
