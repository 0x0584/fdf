/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:45:36 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <time.h>

#include "fdf.h"
#include "draw.h"
#include "matrice.h"
#include "event.h"

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
	env.win = mlx_new_window(env.mlx, WIN_LENGTH, WIN_WIDTH, "FDF");
	env.mat = data;
	mlx_hook(env.win, 5, 0, &mouse_press, &env);
	mlx_hook(env.win, 2, 0, &key_press , &env);
	mlx_string_put(env.mlx, env.win, 800, 500, 0xFFFFFF,
				   "Press any key to start FDF");
	mlx_loop(env.mlx);
	mlx_clear_window(env.mlx, env.win);
	mlx_destroy_window(env.mlx, env.win);
	return (0);
}
