/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:02:41 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/16 15:45:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	tab = (char *)malloc(sizeof(char) * size);
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	return (tab);
}
