/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/08/06 19:09:34 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

#define OFFSET 20

#define FIRE_BRICK			0xB22222
#define DIM_GRAY			0x696969
#define LIGHT_GRAY			0xD3D3D3
#define DARK_GREEN			0x006400
#define COLOR_BLUE			0x0000FF

const int win_length = 2000, win_width = 1000;

void	draw_color_square(t_env *env, t_pnt3d head, t_uint32 size)
{
	t_pnt3d next;
	t_uint32 i;

	i = 0;
	next.x = head.x + size;
	next.y = head.y;
	while (i++ <= size)
	{
		draw_line(env->mlx, env->win, head ,next, head.color);
		next.y++;
		head.y++;
	}
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_env *env;
	env = param;
	if (button)
		;

	if (x >= 70 && x <= 100 && y >= 900 && y <= 930)
		default_color(FIRE_BRICK);
	if (x >= 110 && x <= 140 && y >= 900 && y <= 930)
		default_color(DARK_GREEN);
	if (x >= 150 && x <= 180 && y >= 900 && y <= 930)
		default_color(COLOR_BLUE);

	key_press(-1, param);
	return (0);
}

int main(int argc, char *argv[])
{
	t_fdf_data	*data;
	t_env 		env;
	void 		*mlx_id;
	void 		*win_id;

	if (argc != 2)
		return (0);
	int fd = open(argv[1],O_RDONLY);
	data = fdf_read(fd);
	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, win_length, win_width, "FDF");

	env.win = win_id;
	env.mlx = mlx_id;
	env.mat = data;

	t_pnt3d points[] = {
		{.y = 900, .color = FIRE_BRICK, .x = 70},
		{.y = 900, .color = DARK_GREEN, .x = 110},
		{.y = 900, .color = COLOR_BLUE, .x = 150},
	};

	mlx_string_put(env.mlx, env.win, 150 + 70, 905, LIGHT_GRAY, "Zoom: +/- | Z-axis: u/p | Translation: UP/DOWN LEFT/RIGHT | RotationX: W/X | RotationY: A/D | RotationZ: Q/E | Projection: Parallele(1)/isometrique(2) ");


	mlx_string_put(env.mlx, env.win, 94, 870, LIGHT_GRAY, "Colors: ");

	draw_color_square(&env, points[0], 30);
	draw_color_square(&env, points[1], 30);
	draw_color_square(&env, points[2], 30);

	mlx_hook(win_id, 5, 0, &mouse_press, &env);
	mlx_hook(win_id, 2, 0, &key_press , &env);
	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id);
	return (0);
}
