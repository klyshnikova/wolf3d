/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cpy_str(t_wolf *e, char *line)
{
	if (!(e->tab[e->i] = (char *)malloc(sizeof(char) * e->east + 1)))
		error();
	ft_strcpy(e->tab[e->i], line);
	free(line);
}

void	wall_check(int fd, t_wolf *wolf)
{
	char *line;

	line = NULL;
	if (!(wolf->tab = (char **)malloc(sizeof(char *) * wolf->south + 1)))
		error();
	while ((get_next_line(fd, &line)) == 1)
	{
		cpy_str(wolf, line);
		wolf->i++;
	}
	free(line);
	if (side(wolf) == -1)
		error();
}

int		side(t_wolf *wolf)
{
	wolf->bou = 0;
	while (wolf->bou <= wolf->east)
	{
		if (wolf->tab[0][wolf->bou] != '1')
			return (-1);
		wolf->bou++;
	}
	wolf->bou = 1;
	while (wolf->bou <= (wolf->south - 1))
	{
		if (wolf->tab[wolf->bou][0] != '1')
			return (-1);
		if (wolf->tab[wolf->bou][wolf->east] != '1')
			return (-1);
		wolf->bou++;
	}
	wolf->bou = 0;
	while (wolf->bou <= wolf->east)
	{
		if (wolf->tab[wolf->south][wolf->bou] != '1')
			return (-1);
		wolf->bou++;
	}
	return (1);
}
