/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:37:12 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <time.h>

#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

const int win_length = 2000;
const int win_width = 1000;

int		mouse_press(int button, int x, int y, void *param)
{
	t_env *env;

	env = param;
	(void)button;
	if (x >= 70 && x <= 100 && y >= 900 && y <= 930)
		default_color(FIRE_BRICK);
	if (x >= 110 && x <= 140 && y >= 900 && y <= 930)
		default_color(DARK_GREEN);
	if (x >= 150 && x <= 180 && y >= 900 && y <= 930)
		default_color(COLOR_BLUE);
	key_press(-1, param);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_fdf_data	*data;
	t_env 		env;
	int			fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1],O_RDONLY);
	data = fdf_read(fd);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, win_length, win_width, "FDF");
	env.mat = data;
	mlx_hook(env.win, 5, 0, &mouse_press, &env);
	mlx_hook(env.win, 2, 0, &key_press , &env);
	mlx_string_put(env.mlx, env.win, 500, 500, 0xFFFFFF,
				   "Press any key to start FDF");
	mlx_loop(env.mlx);
	mlx_clear_window(env.mlx, env.win);
	mlx_destroy_window(env.mlx, env.win);
	return (0);
}
