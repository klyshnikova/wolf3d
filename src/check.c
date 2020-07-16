/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_line(char *line, t_wolf *wolf)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '0') || (line[i] == 'X') || (line[i] == '1'))
		{
			if (line[i] == 'X')
				wolf->xchecker++;
			if (wolf->xchecker > 1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	free(line);
	return (1);
}

int		check(int fd, t_wolf *wolf)
{
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (check_line(line, wolf) == 0)
			return (-1);
		if (wolf->south == 0)
			wolf->previous = ft_strlen(line);
		else
		{
			if (wolf->previous != ft_strlen(line))
				return (-1);
			wolf->previous = ft_strlen(line);
		}
		wolf->south++;
	}
	free(line);
	wolf->east = wolf->previous - 1;
	wolf->south--;
	if (wolf->xchecker != 1)
		return (-1);
	if (wolf->south < 2 || wolf->east < 2)
		return (-1);
	return (1);
}

int		check_map(int fd, t_wolf *wolf)
{
	if (check(fd, wolf) == -1)
		return (-1);
	return (1);
}
