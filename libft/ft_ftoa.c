/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 02:45:42 by archid-           #+#    #+#             */
/*   Updated: 2019/08/07 15:40:23 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float f, t_int8 precision)
{
	t_float32 foo;

	foo.f = f;
	ft_putnbr(precision);
	ft_putendl("");
	ft_putnbr(foo.ieee.m);
	ft_putendl("");
	ft_putnbr(foo.ieee.e);
	ft_putendl("");
	ft_putnbr(foo.ieee.s);
	ft_putendl("");
	return (NULL);
}
