/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:47:00 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 20:35:15 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "point.h"


typedef struct	s_fdf_data
{
	t_pnt3d			**base;
	t_uint32		length;
	t_uint32		width;
}				t_fdf_data;

t_fdf_data		*fdf_read(const int fd);
void			fdf_free(t_fdf_data **ptr_fdf);

#endif
