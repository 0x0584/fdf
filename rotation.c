/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:25:11 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 21:48:17 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotation.h"

static void		rotate_point(t_pnt3d *rotted, t_pnt3d ori, t_info ifdf,
								t_rot_type rot)
{
	if (rot == ROT_X)
	{
		rotted->x = ori.x;
		rotted->y = ori.y * cos(ifdf.angle[rot]) + ori.z * sin(ifdf.angle[rot]);
		rotted->z = ori.z * cos(ifdf.angle[rot]) - ori.y * sin(ifdf.angle[rot]);
	}
	else if (rot == ROT_Y)
	{
		rotted->x = ori.x * cos(ifdf.angle[rot]) + ori.z * sin(ifdf.angle[rot]);
		rotted->y = ori.y;
		rotted->z = ori.z * cos(ifdf.angle[rot]) - ori.x * sin(ifdf.angle[rot]);
	}
	else if (rot == ROT_Z)
	{
		rotted->x = ori.x * cos(ifdf.angle[rot]) - ori.y * sin(ifdf.angle[rot]);
		rotted->y = ori.x * sin(ifdf.angle[rot]) + ori.y * cos(ifdf.angle[rot]);
		rotted->z = ori.z;
	}
}

t_pnt3d			**rotation(t_pnt3d **mat, t_info *ifdf, t_rot_type rot,
								t_env *env)
{
	t_pnt3d		**ret_mat;
	t_uint32	i;
	t_uint32	j;

	i = 0;
	ret_mat = point_alloc_array(ifdf->length, ifdf->width);
	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			rotate_point(&ret_mat[i][j], mat[i][j], *ifdf, rot);
			j++;
		}
		i++;
	}
	return (ret_mat);
}

t_pnt3d			**redim(t_pnt3d **mat, t_info *ifdf, t_env *env)
{
	t_pnt3d		**ret_mat;
	t_uint32	i;
	t_uint32	j;

	i = 0;
	ret_mat = point_alloc_array(ifdf->length, ifdf->width);
	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			ret_mat[i][j].x = mat[i][j].x + j * ifdf->spacing;
			ret_mat[i][j].y = mat[i][j].y + i * ifdf->spacing;
			ret_mat[i][j].z = (mat[i][j].z != 0) ?
				(mat[i][j].z + ifdf->z_incr * mat[i][j].z) : (mat[i][j].z);
			ret_mat[i][j].color = mat[i][j].color;
			j++;
		}
		i++;
	}
	return (ret_mat);
}

t_pnt3d			**redim2d(t_pnt3d **mat, t_info *ifdf, t_env *env)
{
	t_pnt3d		**ret_mat;
	t_uint32	i;
	t_uint32	j;

	i = 0;
	ret_mat = point_alloc_array(ifdf->length, ifdf->width);
	while (i < env->mat->length)
	{
		j = 0;
		while (j < env->mat->width)
		{
			ret_mat[i][j] = (t_pnt3d){
				mat[i][j].x + ifdf->horiz,
				mat[i][j].y + ifdf->verti,
				0,
				mat[i][j].color
			};
			j++;
		}
		i++;
	}
	return (ret_mat);
}
