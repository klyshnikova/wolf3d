/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:21:50 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/15 20:28:55 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (char*)dst;
	s2 = (char*)src;
	i = 0;
	while (n--)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
