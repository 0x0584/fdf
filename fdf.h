/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:47:00 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 21:07:53 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>

# include "gnl.h"
# include "point.h"
# include "libft/libft.h"

# define WIN_WIDTH				1000
# define WIN_LENGTH				2000

# define INIT_SPACING			15
# define INIT_Z_INCR			0
# define INIT_HORIZ				650
# define INIT_VERTI				350
# define INIT_ANGLE_X			-0.2
# define INIT_ANGLE_Y			0
# define INIT_ANGLE_Z			-0.5
# define INIT_PROJECTION_TYPE	'p'

# define DEF_SPACING			5
# define DEF_Z_INCR				2
# define DEF_HORIZ				10
# define DEF_VERTI				10
# define DEF_ANGLE_X			0.05
# define DEF_ANGLE_Y			0.05
# define DEF_ANGLE_Z			0.05

typedef struct	s_fdf_data
{
	t_pnt3d			**base;
	t_uint32		length;
	t_uint32		width;
}				t_fdf_data;

typedef struct	s_fdf_info
{
	t_uint64	length;
	t_uint64	width;

	t_uint64	spacing;
	t_uint64	z_incr;

	t_uint64	horiz;
	t_uint64	verti;

	double		angle[3];
	char		proj_type;
}				t_info;

typedef enum	e_rotation_types
{
	ROT_X, ROT_Y, ROT_Z
}				t_rot_type;

t_fdf_data		*fdf_read(const int fd);
void			fdf_free(t_fdf_data **ptr_fdf);
t_info			*get_fdf_info(void);

#endif
