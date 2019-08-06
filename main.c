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
const double depth = 1;

 

// int	mouse_move(int x, int y, void *param)
// {
// 	t_env *env;

// 	env = param;
// 	draw_line(env->mlx, env->win, (t_pnt3d){1000,500,0},(t_pnt3d){x,y,0});
// 	return (0);
// }



int main(int argc, char *argv[])
{
	t_fdf_data	*data;
	t_fdf_data2 *rec;
	t_pnt3d **resX,**resY,**resZ;
	t_env 	env;
	void *mlx_id = NULL, *win_id = NULL;

	int fd = open(argv[1],O_RDONLY);
	data = fdf_read(fd);
	mlx_id = mlx_init();
	win_id = mlx_new_window(mlx_id, win_length, win_width, "FDF");

	env.win = win_id;
	env.mlx = mlx_id;
	env.mat = data;

	// mlx_hook(win_id, 6, 0, &mouse_move, &env);
	mlx_hook(win_id, 2, 0, &key_press , &env);
	mlx_loop(mlx_id);
	mlx_clear_window(mlx_id, win_id);
	mlx_destroy_window(mlx_id, win_id); 
	return (0);
}
