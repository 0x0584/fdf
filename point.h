/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:11:53 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 01:33:38 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "libft/libft.h"

typedef struct	s_3d_point
{
	t_int64 x;
	t_int64 y;
	t_int64 z;
}				t_pnt3d;

typedef struct	s_2d_point
{
	t_int64 x;
	t_int64 y;
}				t_pnt2d;

t_pnt2d		point_2d_init(t_int64 x, t_int64 y);
t_pnt3d		point_3d_init(t_int64 x, t_int64 y, t_int64 z);
t_pnt3d		*get_coords_in_line(char *line, t_uint32 y);
void		point_plot(void *mlx_id, void *win_id, t_pnt2d point);

// void		point_dbg(t_pnt_array pnts);

#endif
