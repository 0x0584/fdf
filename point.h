/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:11:53 by archid-           #+#    #+#             */
/*   Updated: 2019/07/15 22:41:53 by archid-          ###   ########.fr       */
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
}				t_pnt;

typedef struct	s_point_array
{
	t_pnt **base;
	t_uint32 length;
	t_uint32 width;
}				t_pnt_array;

void		point_init(t_pnt *pnt, t_int64 x, t_int64 y, t_int64 z);
t_pnt_array point_read_fdf(const int fd);
void		point_dbg(t_pnt_array pnts);

#endif
