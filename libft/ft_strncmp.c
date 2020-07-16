/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:24:49 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/11 15:32:04 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i])
		&& i < (n - 1))
		i++;
	if (s1[i] != s2[i] && n > 0)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		return (diff);
	}
	else
		return (0);
}
