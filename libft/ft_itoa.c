/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:27:54 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/18 16:27:56 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_i(int n)
{
	int		len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		ft_qwerty(char *s, int n, int len, int neg)
{
	while (len--)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return ((char)s);
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*res;

	neg = 0;
	if (n > -2147483648 && n <= 2147483647)
	{
		if (n < 0)
		{
			neg = 1;
			n *= -1;
		}
		len = ft_i(n) + neg;
		if (!(res = ft_strnew(len)))
			return (NULL);
		ft_qwerty(res, n, len, neg);
		return (res);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}
