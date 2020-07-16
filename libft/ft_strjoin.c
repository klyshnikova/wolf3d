/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:32:25 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/16 16:34:01 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;

	if (s1 && s2)
	{
		if (!(str_new = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
			return (NULL);
		str_new = ft_strcpy(str_new, s1);
		str_new = ft_strcat(str_new, s2);
		return (str_new);
	}
	return (NULL);
}
