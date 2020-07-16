/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:01:56 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/17 18:20:17 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	p;
	size_t	i;

	s = ft_strlen(dst);
	p = ft_strlen(src);
	i = 0;
	if (size <= s)
		return (p + size);
	while ((dst[i] != '\0') && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (s + p);
}
