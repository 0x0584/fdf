/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:48:53 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 21:09:26 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "point.h"
# include "fdf.h"
# include "event.h"

t_pnt3d		**projection(t_pnt3d **matrix, t_info *ifdf, t_env *env);

#endif
