/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 21:12:05 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "fdf.h"
#include "draw.h"
#include "matrice.h"

#define OFFSET 20

#define FIRE_BRICK			0xB22222
#define DIM_GRAY			0x696969
#define LIGHT_GRAY			0xD3D3D3
#define DARK_GREEN			0x006400


// void	do_draw_3d_cube(void *mlx_id, void *win_id, t_pnt3d origin)
// {
// 	t_pnt3d triangle[] = {
// 		{0,0,0},
// 		{0,1,0},
// 		{1,0,0},
// 	};
// }

// void	do_draw_3d_shape(void *mlx_id, void *win_id, t_pnt3d origin)
// {
// 	int i = 0;
// 	while (i < 100)
// 		mlx_pixel_put(mlx_id, win_id, (origin.x + i++) / origin.z,
// 						origin.y / origin.z, FIRE_BRICK);
// 	i = 0;
// 	while (i < 100)
// 		mlx_pixel_put(mlx_id, win_id, origin.x / origin.z,
// 					  (origin.y + i++) / origin.z, FIRE_BRICK);

// }

// void	do_draw_3d_plan(void *mlx_id, void *win_id, t_pnt3d origin)
// {
// 	int foo;
// 	int offset;

// 	offset = 0;
// 	while (offset <= 2 * origin.x) {
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, foo / origin.z,
// 							offset / origin.z, DIM_GRAY);
// 			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
// 		}
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, foo / origin.z,
// 							offset / origin.z, LIGHT_GRAY);
// 			foo += OFFSET;
// 		}
// 		offset += OFFSET;
// 	}

// 	offset = 0;
// 	while (offset <= 2 * origin.x) {
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, offset / origin.z,
// 							foo / origin.z, DIM_GRAY);
// 			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
// 		}
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, offset / origin.z,
// 							foo / origin.z, LIGHT_GRAY);
// 			foo += OFFSET;
// 		}
// 		offset += OFFSET;
// 	}

// }

// void	do_draw_2d_plan(void *mlx_id, void *win_id, t_pnt2d origin)
// {
// 	int foo;
// 	int offset;

// 	offset = 0;
// 	while (offset <= 2 * origin.x) {
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, foo, offset, DIM_GRAY);
// 			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
// 		}
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, foo, offset, LIGHT_GRAY);
// 			foo += OFFSET;
// 		}
// 		offset += OFFSET;
// 	}

// 	offset = 0;
// 	while (offset <= 2 * origin.x) {
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, offset, foo, DIM_GRAY);
// 			foo += (foo + 1) % OFFSET == 0 ? 2 : 1;
// 		}
// 		foo = 0;
// 		while (foo <= origin.x * 2) {
// 			mlx_pixel_put(mlx_id, win_id, offset, foo, LIGHT_GRAY);
// 			foo += OFFSET;
// 		}
// 		offset += OFFSET;
// 	}

// }

// void	do_draw_2d_line(void *mlx_id, void *win_id, t_pnt2d origin,
// 							t_pnt2d a, t_pnt2d b)
// {
// 	int foo = 100;

// 	while (foo--)
// 		mlx_pixel_put(mlx_id, win_id,
// 						a.x + origin.x + foo, a.y + origin.y + foo * 2,
// 						FIRE_BRICK);
// 	foo = 100;
// 	while (foo--)
// 		mlx_pixel_put(mlx_id, win_id,
// 						b.x + origin.x + foo, b.y + origin.y + foo * 2,
// 						DARK_GREEN);
// }

// void	do_mlx_test(void)
// {
// 	const t_uint32 length = 3, width = 4;
// 	t_pnt2d points[length][width] = {
// 		{{1,0}, {0,0}, {2,3}, {2,3},},
// 		{{0,1}, {0,1}, {3,2}, {3,4},},
// 		{{0,0}, {1,0}, {1,3}, {2,3},},
// 	};

// 	void *mlx_id;
// 	void *win_id;

// 	t_pnt2d index = {0,0};
// 	mlx_id = mlx_init();
// 	win_id = mlx_new_window(mlx_id,
// 							width * OFFSET,
// 							length * OFFSET,
// 							"FDF");

// 	t_pnt2d origin = {width * OFFSET / 2, length * OFFSET / 2};

// 	index.y = 0;
// 	while (index.y < length)
// 	{
// 		index.x = 0;
// 		while (index.x < width)
// 		{
// 			printf("%ld, %ld\n", points[index.y][index.x].x,
// 									points[index.y][index.x].y);
// 			int foo = 100;
// 			while (foo--)
// 				mlx_pixel_put(mlx_id, win_id,
// 							  origin.x + points[index.y][index.x].x + foo * 2 ,
// 							  origin.y + points[index.y][index.x].y + foo * 2,
// 							  255);
// 			index.x++;
// 		}
// 		index.y++;
// 	}

// 	mlx_loop(mlx_id);
// 	mlx_clear_window(mlx_id, win_id);
// 	mlx_destroy_window(mlx_id, win_id);

// }

// void	do_read_fdf_test(int argc, char**argv)
// {
// 	t_fdf_data *fdf;
// 	t_uint64 i, j;
// 	int fd;
// 	int foo;

// 	if (argc != 2 || !((fd = open(argv[1], O_RDONLY)) >= 0))
// 		return ;

// 	i = 0;
// 	puts("this");
// 	fdf = fdf_read(fd);
// 	puts("this");
// 	while (i < fdf->length)
// 	{
// 		j = 0;
// 		while (j < fdf->width)
// 		{
// 			(void)printf(" >> (x:%ld, y:%ld, z:%ld) ",
// 						 fdf->base[i][j].x,
// 						 fdf->base[i][j].y,
// 						 fdf->base[i][j].z);

			/*
			mlx_string_put(mlx_id, win_id,
						   fdf->base[i][j].x + foo + origin.x,
						   fdf->base[i][j].y + foo + origin.y,
						   FIRE_BRICK,
						   "this is a test");
			*/
			/*
			foo = 50;
			while (foo--)
				mlx_pixel_put(mlx_id, win_id,
							  fdf->base[i][j].x + foo + origin.x,
							  fdf->base[i][j].y + foo + origin.y,
							  FIRE_BRICK);
			*/
// 			j++;
// 		}
// 		i++;
// 	}
// 	fdf_free(&fdf);
// }

// void	do_get_coords_test(void *mlx_id, void *win_id, t_pnt2d origin)
// {
// 	char *str = "10 20 10 -2";
// 	const int width = ft_wordcount(str, ' '), n_tests = 5;
// 	t_uint16 i = 0, j = 0;
// 	t_pnt3d *pnts = NULL;
// 	int foo = 100;

// 	while (i < n_tests)
// 	{
// 		j = 0;
// 		pnts = get_coords_in_line(str, i++);
// 		while (j < width)
// 		{

// 			/* the cast is because printf returns an int, we don't want that! */
// 			(void)printf("(x:%ld, y:%ld, z:%ld) ",
// 						 pnts[j].x, pnts[j].y, pnts[j].z);

// 			mlx_pixel_put(mlx_id, win_id,
// 						  origin.x + pnts[j].x + foo * 2,
// 						  origin.y - pnts[j].y + foo * 2,
// 						  FIRE_BRICK);
// 			foo -= 10;
// 			j++;
// 		}
// 		(void)printf("\n");
// 		j = 0;
// 		free(pnts);
// 	}
// }

const int win_length = 2000, win_width = 1000;
const double depth = 1;

typedef struct s_env
{
	void *mlx;
	void *win;
}				t_env;

int	mouse_move(int x, int y, void *param)
{
	t_env *env;

	env = param;
	draw_line(env->mlx, env->win, (t_pnt3d){1000,500,0},(t_pnt3d){x,y,0});
	return (0);
}

int main(int argc, char *argv[])
{
	const t_uint32 length = 3, width = 4;
	t_pnt3d points[length][width] = {
		{{100,100,0}, {200,100,0}, {300,100,0}, {400,100,0}},
		{{100,200,0}, {200,200,0}, {300,200,0}, {400,200,0}},
		{{100,300,0}, {200,300,0}, {300,300,0}, {400,300,0}},
	};
	t_pnt3d **resX,**resY,**resZ;
	//t_pnt3d *tab;
	float angle = 0.5;
	float rot_matrix_x[3][3] = {{1,0,0},
                              {0,cos(angle),-sin(angle)},
                              {0,sin(angle),cos(angle)}};
	int i = 0;
	int j = 0;
	t_env 	env;
	t_pnt3d pn;
	t_pnt3d pm;
	
	resX = rotationX(points, length, width , angle);
	resY = rotationY(points, length, width , angle);
	resZ = rotationZ(points, length, width , angle);
	//printf ("\n+++%ld++++",res[0][0].y);
	// printf("%ld %ld %ld\n",points[0][0].x, points[0][0].y, points[0][0].z);
	// pn = produit_matrix( points[0][0],  rot_matrix_x);
	// printf("%ld %ld %ld\n",pn.x, pn.y, pn.z);


	// t_pnt2d a,b,c,d,m,n,k,h; 
	// a.x =150 ; a.y = 150;
	// b.x = 150 ; b.y = 350;
	// c.x =150 ; c.y = 350;
	// d.x = 350 ; d.y = 350;
	// m.x =350 ; m.y = 350;
	// n.x = 350 ; n.y = 150;
	// k.x =350 ; k.y = 150;
	// h.x = 150 ; h.y = 150;

	//do_read_fdf_test(argc,argv); 
	 //do_mlx_test(); 

	void *mlx_id = NULL, *win_id = NULL;
	t_pnt2d origin_2d = {win_width / 2, win_length / 2};
	t_pnt3d origin_3d = {win_width / 2, win_length / 2, depth};

	
	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, win_length, win_width, "FDF");
	env.win = win_id;
	env.mlx = mlx_id;
	

	/* do_draw_2d_plan(mlx_id, win_id, origin_2d); */
	/* do_draw_2d_line(mlx_id, win_id, origin_2d, head, tail); */


	// rotationX(points, length, width , angle);
	// printf("%ld %ld %ld",points[0][0].x, points[0][0].y, points[0][0].z);
	// printf("\n%f",cos(0.5));

	// while (i < 3)
	// {
	// 	j = 0;
	// 	while (j < 4) 
	// 	{
	// 		if (j != 3)
	// 		draw_line(mlx_id, win_id, resX[i][j],resX[i][j + 1]);
	// 		//if (i != 0)
	// 		// draw_line(mlx_id, win_id, resX[i][j],resX[i - 1][j]);
	// 		// if (j != 0)
	// 		//draw_line(mlx_id, win_id, resX[i][j],resX[i][j - 1]);
	// 		if(i != 2)
	// 		draw_line(mlx_id, win_id, resX[i][j],resX[i + 1][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while (i < 3)
	// {
	// 	j = 0;
	// 	while (j < 4) 
	// 	{
	// 		if (j != 3)
	// 		draw_line(mlx_id, win_id, resY[i][j],resY[i][j + 1]);
	// 		// if (i != 0)
	// 		// draw_line(mlx_id, win_id, resY[i][j],resY[i - 1][j]);
	// 		// if (j != 0)
	// 		// draw_line(mlx_id, win_id, resY[i][j],resY[i][j - 1]);
	// 		if(i != 2)
	// 		draw_line(mlx_id, win_id, resY[i][j],resY[i + 1][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	while (i < 3)
	{
		j = 0;
		while (j < 4) 
		{
			mlx_pixel_put(mlx_id, win_id, resZ[i][j].x, resZ[i][j].y, 0xFF00FF);
			if (j != 3)
				draw_line(mlx_id, win_id, resZ[i][j],resZ[i][j + 1]);
			// if (i != 0)
			// draw_line(mlx_id, win_id, resZ[i][j],resZ[i - 1][j]);
			// if (j != 0)
			// draw_line(mlx_id, win_id, resZ[i][j],resZ[i][j - 1]);
			if(i != 2)
				draw_line(mlx_id, win_id, resZ[i][j],resZ[i + 1][j]);
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < 3)
	// {
	// 	j = 0;
	// 	while (j < 4) 
	// 	{
	// 		if (j != 3)
	// 		draw_line(mlx_id, win_id, points[i][j],points[i][j + 1]);
	// 		// if (i != 0)
	// 		// draw_line(mlx_id, win_id, points[i][j],points[i - 1][j]);
	// 		// if (j != 0)
	// 		// draw_line(mlx_id, win_id, points[i][j],points[i][j - 1]);
	// 		if(i != 2)
	// 		draw_line(mlx_id, win_id, points[i][j],points[i + 1][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_line(mlx_id, win_id, a,b);
	// draw_line(mlx_id, win_id, c,d);
	// draw_line(mlx_id, win_id, m,n);
	// draw_line(mlx_id, win_id, k,h);


	//do_draw_3d_plan(mlx_id, win_id, origin_3d);
	// do_draw_3d_shape(mlx_id, win_id, origin_3d); 

	// puts("this");
	  //do_read_fdf_test(argc, argv);


	mlx_hook(win_id, 6, 0, &mouse_move, &env);
	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);
	
//printf("%f",cos(0.5));
	return (0);
}
