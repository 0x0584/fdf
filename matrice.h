/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:56:34 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 20:28:57 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

#include "fdf.h"
#include "event.h"

t_pnt3d		**rotation(t_pnt3d **matrix, t_info *ifdf, t_rot_type  rot,
							t_env *env);
t_pnt3d		**projection(t_pnt3d **matrix, t_info *ifdf, t_env *env);
t_pnt3d		**redim(t_pnt3d **mat, t_info *ifdf, t_env *env);
t_pnt3d		**redim2d(t_pnt3d **mat, t_info *ifdf, t_env *env);

#endif
