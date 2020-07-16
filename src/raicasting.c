/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raicasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	start_pos(t_wolf *wolf)
{
	wolf->camera = 2 * wolf->x / (double)wolf->w - 1;
	wolf->ray_posx = wolf->posx;
	wolf->ray_posy = wolf->posy;
	wolf->ray_dirx = wolf->dirx + wolf->plane_x * wolf->camera;
	wolf->ray_diry = wolf->diry + wolf->plane_y * wolf->camera;
	wolf->map_x = (int)wolf->ray_posx;
	wolf->map_y = (int)wolf->ray_posy;
	wolf->hit = 0;
	wolf->side = 0;
	wolf->delta_dist_x = sqrt(1 + (wolf->ray_diry * wolf->ray_diry) /
			(wolf->ray_dirx * wolf->ray_dirx));
	wolf->delta_dist_y = sqrt(1 + (wolf->ray_dirx * wolf->ray_dirx) /
			(wolf->ray_diry * wolf->ray_diry));
}

void	raicast1(t_wolf *wolf)
{
	if (wolf->ray_dirx < 0)
	{
		wolf->stepx = -1;
		wolf->side_dist_x = (wolf->ray_posx - (double)wolf->map_x)
				* wolf->delta_dist_x;
	}
	else
	{
		wolf->stepx = 1;
		wolf->side_dist_x = ((double)wolf->map_x + 1.0
			- wolf->ray_posx) * wolf->delta_dist_x;
	}
	if (wolf->ray_diry < 0)
	{
		wolf->stepy = -1;
		wolf->side_dist_y = (wolf->ray_posy - (double)wolf->map_y)
				* wolf->delta_dist_y;
	}
	else
	{
		wolf->stepy = 1;
		wolf->side_dist_y = ((double)wolf->map_y + 1.0
			- wolf->ray_posy) * wolf->delta_dist_y;
	}
}

void	raicast2(t_wolf *wolf)
{
	while (wolf->hit == 0)
	{
		if (wolf->side_dist_x < wolf->side_dist_y)
		{
			wolf->side_dist_x += wolf->delta_dist_x;
			wolf->map_x += wolf->stepx;
			wolf->side = 0;
		}
		else
		{
			wolf->side_dist_y += wolf->delta_dist_y;
			wolf->map_y += wolf->stepy;
			wolf->side = 1;
		}
		if (wolf->tab[wolf->map_x][wolf->map_y] == 49)
			wolf->hit = 1;
	}
}

void	raycast(t_wolf *wolf)
{
	if (wolf->side == 0)
		wolf->cam_wall = fabs((wolf->map_x - wolf->ray_posx +
				(1 - wolf->stepx) / 2) / wolf->ray_dirx);
	else
		wolf->cam_wall = fabs((wolf->map_y - wolf->ray_posy +
				(1 - wolf->stepy) / 2) / wolf->ray_diry);
	if (wolf->cam_wall <= 0.05)
		wolf->cam_wall = 0.05;
	wolf->line_height = abs((int)(wolf->h / wolf->cam_wall));
	wolf->drawstart = (-1 * (wolf->line_height)) / 2 + wolf->h / 2;
	if (wolf->drawstart < 0)
		wolf->drawstart = 0;
	wolf->drawend = wolf->line_height / 2 + wolf->h / 2;
	if (wolf->drawend >= wolf->h)
		wolf->drawend = wolf->h - 1;
}
