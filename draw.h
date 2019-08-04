/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:30:59 by archid-           #+#    #+#             */
/*   Updated: 2019/07/17 01:39:44 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "point.h"
# include <math.h>

void	draw_line(void *mlx_id, void *win_id, t_pnt2d a, t_pnt2d b, int color);

#endif
