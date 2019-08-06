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
#include "event.h"

#define OFFSET 20

#define FIRE_BRICK			0xB22222
#define DIM_GRAY			0x696969
#define LIGHT_GRAY			0xD3D3D3
#define DARK_GREEN			0x006400

const int win_length = 2000, win_width = 1000;

int mouse_press(int button, int x, int y, void *param)
{
	t_env *env;
	t_pnt3d pnt1;
	t_pnt3d pnt2;
	env = param;
	if (button)
	;
	
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

	mlx_hook(win_id, 5, 0, &mouse_press, &env);
	mlx_hook(win_id, 2, 0, &key_press , &env);
	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id); 
	return (0);
}
