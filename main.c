/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:36:12 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 23:54:03 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "projection.h"
#include "event.h"

int		fdf_close(void *param)
{
	(void)param;
	exit(0);
}

int		is_same_nbr_line(char *argv[])
{
	int		fd;
	int		prec;
	int		curr;
	char	*str;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, &str);
	if (ret == 0)
		return (0);
	prec = ft_wordcount(str, ' ');
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		curr = ft_wordcount(str, ' ');
		if (curr != prec)
			return (0);
	}
	close(fd);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_fdf_data	*data;
	t_env		env;
	int			fd;

	if (argc != 2 || !is_same_nbr_line(argv))
	{
		ft_putendl("Error!");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	data = fdf_read(fd);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_LENGTH, WIN_WIDTH, "FDF");
	env.mat = data;
	mlx_hook(env.win, 5, 0, &mouse_press, &env);
	mlx_hook(env.win, 2, 0, &key_press, &env);
	mlx_hook(env.win, 17, 0, &fdf_close, &env);
	mlx_string_put(env.mlx, env.win, 800, 500, 0xFFFFFF,
					"Press any key to start FDF");
	mlx_loop(env.mlx);
	mlx_clear_window(env.mlx, env.win);
	mlx_destroy_window(env.mlx, env.win);
	return (0);
}
