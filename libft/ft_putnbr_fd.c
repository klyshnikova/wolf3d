/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:48:40 by jemendy           #+#    #+#             */
/*   Updated: 2019/04/16 17:58:41 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0 && fd <= 3)
	{
		if (n > -2147483648 && n <= 2147483647)
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				ft_putnbr_fd(n * -1, fd);
			}
			else if (n > 9)
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putnbr_fd(n % 10, fd);
			}
			else
				ft_putchar_fd(n + 48, fd);
		}
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
	}
}
