/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:50:31 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 15:30:37 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strnprepend(char **dest, const char *prefix, size_t prefixsz)
{
	char	*s;
	size_t	destsz;

	UNLESS_RET(dest && *dest, -1);
	destsz = ft_strlen(*dest);
	UNLESS_RET(s = ft_strnew(destsz + prefixsz), 0);
	while (destsz--)
		s[destsz + prefixsz] = (*dest)[destsz];
	while (prefixsz--)
		s[prefixsz] = prefix[prefixsz];
	ft_strdel(dest);
	*dest = s;
	return (destsz + prefixsz);
}
