/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:16 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 21:09:58 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft/libft.h"

# define BUFF_SIZE				32

typedef enum	e_read_states
{
	failure = -1, eof, success,
}				t_state;

ssize_t			cached_read(const int fd, char **cache);
int				extract_nl_line(char **cache, char **line);
int				get_next_line(const int fd, char **line);

#endif
