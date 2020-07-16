/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

void	closet(t_wolf *wolf)
{
	exit(0);
}

int		usage(void)
{
	ft_putstr_fd("usage: ./wolf3d [map] \n", 2);
	return (-1);
}
