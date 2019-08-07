/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:11:53 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 21:08:57 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "libft/libft.h"
# include "color.h"

typedef struct	s_3d_point
{
	t_int64 x;
	t_int64 y;
	t_int64 z;
	t_color	color;
}				t_pnt3d;

t_pnt3d			point_3d_init(t_int64 x, t_int64 y, t_int64 z, t_color color);
t_pnt3d			*get_coords_in_line(char *line, t_uint32 y);
t_pnt3d			**point_alloc_array(t_uint32 length, t_uint32 width);
void			point_free_array(t_pnt3d **array, t_uint32 length);

#endif
