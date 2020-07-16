/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	shift_speed(t_wolf *wolf)
{
	wolf->speed = 0.05;
	wolf->boost = 0.07;
}

int		key_hook1(int key, t_wolf *wolf)
{
	if (key == ESC)
		closet(wolf);
	if (key == 126)
		wolf->tap_126 = 1;
	if (key == 125)
		wolf->tap_125 = 1;
	if (key == 123)
		wolf->tap_123 = 1;
	if (key == 124)
		wolf->tap_124 = 1;
	if (key == 257)
		wolf->shift = 1;
	return (0);
}

int		key_hook2(int key, t_wolf *wolf)
{
	if (key == 126)
		wolf->tap_126 = 0;
	if (key == 125)
		wolf->tap_125 = 0;
	if (key == 123)
		wolf->tap_123 = 0;
	if (key == 124)
		wolf->tap_124 = 0;
	if (key == 257)
		wolf->shift = 0;
	return (0);
}
