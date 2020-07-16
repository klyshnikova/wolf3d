/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_126(t_wolf *wolf)
{
	if (wolf->tab[(int)(wolf->posx + wolf->dirx * wolf->boost)]
	[(int)(wolf->posy)] != 49)
		wolf->posx += wolf->dirx * wolf->boost;
	if (wolf->tab[(int)(wolf->posx)]
	[(int)(wolf->posy + wolf->diry * wolf->boost)] != 49)
		wolf->posy += wolf->diry * wolf->boost;
}

void	key_125(t_wolf *wolf)
{
	if (wolf->tab[(int)(wolf->posx - wolf->dirx * wolf->boost)]
		[(int)(wolf->posy)] != 49)
		wolf->posx -= wolf->dirx * wolf->boost;
	if (wolf->tab[(int)(wolf->posx)]
		[(int)(wolf->posy - wolf->diry * wolf->boost)] != 49)
		wolf->posy -= wolf->diry * wolf->boost;
}

void	key_123(t_wolf *wolf)
{
	wolf->old_dir_x = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(wolf->speed) - wolf->diry * sin(wolf->speed);
	wolf->diry = wolf->old_dir_x * sin(wolf->speed)
			+ wolf->diry * cos(wolf->speed);
	wolf->old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(wolf->speed)
		- wolf->plane_y * sin(wolf->speed);
	wolf->plane_y = wolf->old_plane_x * sin(wolf->speed)
		+ wolf->plane_y * cos(wolf->speed);
}

void	key_124(t_wolf *wolf)
{
	wolf->old_dir_x = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(wolf->speed * -1)
			- wolf->diry * sin(wolf->speed * -1);
	wolf->diry = wolf->old_dir_x * sin(wolf->speed * -1)
			+ wolf->diry * cos(wolf->speed * -1);
	wolf->old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(wolf->speed * -1)
		- wolf->plane_y * sin(wolf->speed * -1);
	wolf->plane_y = wolf->old_plane_x * sin(wolf->speed * -1)
		+ wolf->plane_y * cos(wolf->speed * -1);
}
