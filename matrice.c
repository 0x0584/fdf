/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:25:11 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:29:17 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrice.h"

static t_pnt3d		projection_iso(t_pnt3d point)
{
    t_pnt3d ret2d;

    ret2d.x = (point.x - point.y) * cos(0.523599);
    ret2d.y = (point.x + point.y) * sin(0.523599) - point.z;
    ret2d.color = point.color;
    return (ret2d);
}

static t_pnt3d		projection_parallel(t_pnt3d point)
{
    t_pnt3d ret2d;

    ret2d.x = point.x;
    ret2d.y = point.y;
    ret2d.z = point.z;
    ret2d.color = point.color;
    return (ret2d);
}

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

t_pnt3d		**projection(t_pnt3d **matrix, t_info *ifdf, t_env *env)
{
    t_pnt3d		**projected;
    t_uint32	i = 0;
    t_uint32	j;

    i = 0;
	projected = point_alloc_array(ifdf->length, ifdf->width);
    while(i < env->mat->length)
    {
        j = 0;
        while (j < env->mat->width)
        {
			if (ifdf->proj_type == 'i')
				projected[i][j] = projection_iso(matrix[i][j]);
			if (ifdf->proj_type == 'p')
				projected[i][j] = projection_parallel(matrix[i][j]);
            j++;
        }
        i++;
    }
    return (projected);
}

t_pnt3d			**rotation(t_pnt3d **mat, t_info *ifdf, t_rot_type rot,
								t_env *env)
{

    t_pnt3d		**ret_mat;
	t_uint32	i;
    t_uint32	j;

    i = 0;
	ret_mat = point_alloc_array(ifdf->length, ifdf->width);
    while(i < env->mat->length)
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

t_pnt3d		**redim(t_pnt3d **mat, t_info *ifdf, t_env *env)
{
    t_pnt3d **ret_mat;
	t_uint32 i = 0;
    t_uint32 j;

    ret_mat = point_alloc_array(ifdf->length, ifdf->width);
    i = 0;
    while (i < env->mat->length)
	{
		ft_putendl("\nI");
		j = 0;
		while (j < env->mat->width)
		{
			ft_putstr(" J");
			ret_mat[i][j].x = mat[i][j].x + j * ifdf->spacing;
			ret_mat[i][j].y = mat[i][j].y + i * ifdf->spacing;
            ret_mat[i][j].z = (mat[i][j].z != 0) ?
				(mat[i][j].z + ifdf->z_incr * mat[i][j].z) : (mat[i][j].z);
			ret_mat[i][j].color = mat[i][j].color;
			j++;
		}
		i++;
	}
	ft_putendl("this");

    return(ret_mat);
}

t_pnt3d    **redim2d(t_pnt3d **mat, t_info *ifdf, t_env *env)
{
    t_pnt3d **ret_mat;
	t_uint32 i = 0;
    t_uint32 j;

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
