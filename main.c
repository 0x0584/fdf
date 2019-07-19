/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 05:59:14 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "fdf.h"
#include "draw.h"

#define OFFSET 20

#define FIRE_BRICK			0xB22222
#define DIM_GRAY			0x696969
#define LIGHT_GRAY			0xD3D3D3
#define DARK_GREEN			0x006400

void	do_draw_3d_cube(void *mlx_id, void *win_id, t_pnt3d origin)
{
	t_pnt3d triangle[] = {
		{0,0,0},
		{0,1,0},
		{1,0,0},
	};
}

void	do_draw_3d_shape(void *mlx_id, void *win_id, t_pnt3d origin)
{
	int i = 0;
	while (i < 100)
		mlx_pixel_put(mlx_id, win_id, (origin.x + i++) / origin.z,
						origin.y / origin.z, FIRE_BRICK);
	i = 0;
	while (i < 100)
		mlx_pixel_put(mlx_id, win_id, origin.x / origin.z,
					  (origin.y + i++) / origin.z, FIRE_BRICK);

}

void	do_draw_3d_plan(void *mlx_id, void *win_id, t_pnt3d origin)
{
	int foo;
	int offset;

	offset = 0;
	while (offset <= 2 * origin.x) {
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, foo / origin.z,
							offset / origin.z, DIM_GRAY);
			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
		}
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, foo / origin.z,
							offset / origin.z, LIGHT_GRAY);
			foo += OFFSET;
		}
		offset += OFFSET;
	}

	offset = 0;
	while (offset <= 2 * origin.x) {
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, offset / origin.z,
							foo / origin.z, DIM_GRAY);
			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
		}
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, offset / origin.z,
							foo / origin.z, LIGHT_GRAY);
			foo += OFFSET;
		}
		offset += OFFSET;
	}

}

void	do_draw_2d_plan(void *mlx_id, void *win_id, t_pnt2d origin)
{
	int foo;
	int offset;

	offset = 0;
	while (offset <= 2 * origin.x) {
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, foo, offset, DIM_GRAY);
			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
		}
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, foo, offset, LIGHT_GRAY);
			foo += OFFSET;
		}
		offset += OFFSET;
	}

	offset = 0;
	while (offset <= 2 * origin.x) {
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, offset, foo, DIM_GRAY);
			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
		}
		foo = 0;
		while (foo <= origin.x * 2) {
			mlx_pixel_put(mlx_id, win_id, offset, foo, LIGHT_GRAY);
			foo += OFFSET;
		}
		offset += OFFSET;
	}

}

void	do_draw_2d_line(void *mlx_id, void *win_id, t_pnt2d origin,
							t_pnt2d a, t_pnt2d b)
{
	int foo = 100;

	while (foo--)
		mlx_pixel_put(mlx_id, win_id,
						a.x + origin.x + foo, a.y + origin.y + foo * 2,
						FIRE_BRICK);
	foo = 100;
	while (foo--)
		mlx_pixel_put(mlx_id, win_id,
						b.x + origin.x + foo, b.y + origin.y + foo * 2,
						DARK_GREEN);
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

void	do_get_coords_test(void *mlx_id, void *win_id, t_pnt2d origin)
{
	char *str = "10 20 10 -2";
	const int width = ft_wordcount(str, ' '), n_tests = 5;
	t_uint16 i = 0, j = 0;
	t_pnt3d *pnts = NULL;
	int foo = 100;

	while (i < n_tests)
	{
		j = 0;
		pnts = get_coords_in_line(str, i++);
		while (j < width)
		{

			/* the cast is because printf returns an int, we don't want that! */
			(void)printf("(x:%ld, y:%ld, z:%ld) ",
						 pnts[j].x, pnts[j].y, pnts[j].z);

			mlx_pixel_put(mlx_id, win_id,
						  origin.x + pnts[j].x + foo * 2,
						  origin.y - pnts[j].y + foo * 2,
						  FIRE_BRICK);
			foo -= 10;
			j++;
		}
		(void)printf("\n");
		j = 0;
		free(pnts);
	}
}
void	draw_line2(void *mlx_id, void *win_id, int w,int h/*t_pnt2d a, t_pnt2d b*/)
{
	/* TODO: draw a line from point A to point B
	 *
	 * IDEA:
	 *
	 * see if a line have passed the middle of the pixle,
	 * if so, print the y+1 point, else print y
	 */
	int x1 = 50, y1 = 50;
	int x2 = 200, y2 = 180;
	int x3 = 150, y3 = 130;
	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);
	float coefDir = dy/dx;
	float dx1 = abs(x3 - x1);
	float dy1 = abs(y3 - y1);
	float coefDir2 = dy1/dx1;

	int x = 0;
	float y = 0;
	h = 0;
	while (x < w)
	{
		y = coefDir*x + y1;
		y2 = (int)(y + 0.5f);
		//mlx_pixel_put(mlx_id, win_id,x,y, 0xFFFFFF);
		mlx_pixel_put(mlx_id, win_id,x,y2, 0x00FFAA);
		printf ("\nx1 = %d | y1 = %d | y = %.2f | y2 = %d",x1,(int)y,y, (int)y2);
		x++;
	}
	x = 0;
	y = 0;
	while (x < w)
	{
		y = coefDir2*x + y1;
		y3 = (int)(y + 0.5f);
		//mlx_pixel_put(mlx_id, win_id,x,y, 0xFFFFFF);
		mlx_pixel_put(mlx_id, win_id,x,y3, 0x00FFAA);
		printf ("\nx1 = %d | y1 = %d | y = %.2f | y2 = %d",x1,(int)y,y, (int)y2);
		x++;
	}
	
}

const int win_length = 200, win_width = 200;
const double depth = 1;

int main(int argc, char *argv[])
{
	/* do_read_fdf_test(); */
	/* do_mlx_test(); */

	void *mlx_id, *win_id;
	t_pnt2d origin_2d = {win_width / 2, win_length / 2};
	t_pnt3d origin_3d = {win_width / 2, win_length / 2, depth};

	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, win_length, win_width, "FDF");


	/* do_draw_2d_plan(mlx_id, win_id, origin_2d); */
	/* do_draw_2d_line(mlx_id, win_id, origin_2d, head, tail); */

	draw_line2(mlx_id, win_id, 700,0);

	//do_draw_3d_plan(mlx_id, win_id, origin_3d);
	//do_draw_3d_shape(mlx_id, win_id, origin_3d); 

	do_get_coords_test(mlx_id, win_id, origin_2d);

	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);

	return (0);
}
