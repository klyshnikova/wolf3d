/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:04:07 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/15 20:07:43 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (dst < src)
	{
		while (len--)
			*s1++ = *s2++;
	}
	if (dst > src)
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (dst);
}
