/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:54:39 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/09 18:38:18 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		q;
	int		w;
	char	*e;

	q = 0;
	w = 0;
	while (src[q] != '\0')
		q++;
	e = (char*)malloc(sizeof(*src) * (q + 1));
	if (e == 0)
		return (0);
	while (src[w] != '\0')
	{
		e[w] = src[w];
		w++;
	}
	e[w] = '\0';
	return (e);
}
