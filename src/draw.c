/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	roof_floor(t_wolf *wolf)
{
	wolf->l = 0;
	while (wolf->l < wolf->h)
	{
		if (wolf->l < wolf->drawstart)
			pix_to_img(wolf, 0x3d3d3d);
		else if (wolf->l >= wolf->drawstart && wolf->l <= wolf->drawend)
			pix_to_img(wolf, wolf->color);
		else
		{
			if (wolf->hit == 1)
				pix_to_img(wolf, 0x698b69);
		}
		wolf->l++;
	}
}

void	recreation_img(t_wolf *wolf)
{
	mlx_destroy_image(wolf->mlx, wolf->img_ptr);
	wolf->img_ptr = mlx_new_image(wolf->mlx, 750, 750);
}

void	color_wall(t_wolf *wolf)
{
	if (wolf->side == 0)
	{
		if (wolf->stepx < 0)
			wolf->color = 0x7ec0ee;
		else
			wolf->color = 0x8b8b;
	}
	else
	{
		if (wolf->stepy < 0)
			wolf->color = 0xffe4c4;
		else
			wolf->color = 0xe0eeee;
	}
}

int		draw_map(t_wolf *wolf)
{
	wolf->x = 0;
	while (wolf->x < wolf->w)
	{
		start_pos(wolf);
		raicast1(wolf);
		raicast2(wolf);
		raycast(wolf);
		color_wall(wolf);
		roof_floor(wolf);
		wolf->x++;
	}
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img_ptr, 0, 0);
	return (0);
}

void	pix_to_img(t_wolf *wolf, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = wolf->x * (wolf->bpp / 8) + wolf->l * (wolf->sizeline);
	while (i < (wolf->bpp / 8))
	{
		wolf->img_str[p + i] = color;
		color >>= 8;
		i++;
	}
}
