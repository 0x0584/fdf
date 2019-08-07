/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:49:17 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:50:04 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include "event.h"

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
