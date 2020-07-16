/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:48 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/15 17:28:37 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if ((res > 922337203685477580 || (res == 922337203685477580 &&
			(str[i] - 48) > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580 &&
			(str[i] - 48) > 8)) && sign == -1)
			return (0);
	}
	return ((int)(res * sign));
}
