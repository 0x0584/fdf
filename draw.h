/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:30:59 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 18:34:13 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "event.h"
# include "color.h"

void			draw_line(t_env *env, t_pnt3d a, t_pnt3d b, t_color color);
void			draw_color_square(t_env *env, t_pnt3d head, t_uint32 size);
void			draw_map(t_env *env, t_color color, t_pnt3d **mat);
void			draw_edge(t_env *env);

#endif
