/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:01:11 by archid-           #+#    #+#             */
/*   Updated: 2019/07/16 01:31:00 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

t_state		extract_nl_line(char **cache, char **line)
{
	char	*nl;
	char	*old_cache;

	ASSERT_RET(!cache || !*cache || !line, failure);
	old_cache = *cache;
	UNLESS_RET(nl = ft_strchr(*cache, '\n'), false);
	*nl = '\0';
	UNLESS_RET(*line = ft_strdup(*cache), failure);
	UNLESS_RET(*cache = ft_strdup(nl + 1), failure);
	free(old_cache);
	return (true);
}

ssize_t		cached_read(const int fd, char **cache)
{
	char		*buff;
	char		*old_cache;
	ssize_t		nbytes;

	UNLESS_RET(buff = ALLOC(char *, 1, BUFF_SIZE + 1), failure);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		if (*cache == NULL)
			*cache = ft_strdup(buff);
		else
		{
			old_cache = *cache;
			*cache = ft_strjoin(old_cache, buff);
			free(old_cache);
		}
		if (ft_strchr(*cache, '\n'))
			break ;
	}
	ft_strdel(&buff);
	return (nbytes);
}

int			get_next_line(const int fd, char **line)
{
	static char	*cache[0xFF] = {NULL};
	ssize_t		nbytes;

	ASSERT_RET(line == NULL || fd < 0, failure);
	ASSERT_RET(BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0, failure);
	ASSERT_RET(cache[fd] && extract_nl_line(&cache[fd], line) > 0, success);
	*line = NULL;
	ASSERT_RET((nbytes = cached_read(fd, &cache[fd])) < 0, failure);
	if (nbytes == 0 && cache[fd])
	{
		*line = ft_strdup(cache[fd]);
		ft_strdel(&cache[fd]);
		return ((*line && ft_strlen(*line)) ? success : eof);
	}
	return (extract_nl_line(&cache[fd], line) > 0);
}
