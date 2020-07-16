/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_wolf *wolf)
{
	wolf->w = 750;
	wolf->h = 750;
	wolf->posx = 1;
	wolf->posy = 1;
	wolf->plane_y = -0.9;
	wolf->xchecker = 0;
	wolf->south = 0;
	wolf->previous = 0;
	wolf->color = 0x512F0D;
}

int		key_hook3(t_wolf *wolf)
{
	recreation_img(wolf);
	if (wolf->tap_126 == 1)
		key_126(wolf);
	if (wolf->tap_125 == 1)
		key_125(wolf);
	if (wolf->tap_123 == 1)
		key_123(wolf);
	if (wolf->tap_124 == 1)
		key_124(wolf);
	if (wolf->shift == 1)
		shift_speed(wolf);
	else
	{
		wolf->boost = 0.03;
		wolf->speed = 0.03;
	}
	draw_map(wolf);
	return (0);
}

int		hero_init(t_wolf *wolf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= wolf->south)
	{
		while (x <= wolf->east)
		{
			if (wolf->tab[y][x] == 'X')
			{
				wolf->posx = y;
				wolf->posy = x;
				wolf->dirx = 1;
				wolf->diry = 0;
				wolf->speed = 0.03;
				wolf->boost = 0.03;
				return (0);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

void	initialize_mlx(t_wolf *wolf)
{
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, 750, 750, "wolf3d");
	wolf->img_ptr = mlx_new_image(wolf->mlx, 750, 750);
	wolf->img_str = mlx_get_data_addr(wolf->img_ptr, &(wolf->bpp),
			&(wolf->sizeline), &(wolf->endian));
}

int		main(int ac, char **av)
{
	t_wolf		wolf;
	int			fd;

	fd = 0;
	if (ac != 2)
		return (usage());
	if (!(fd = open(av[1], O_RDONLY)))
		return (error());
	init_map(&wolf);
	if (check_map(fd, &wolf) != 1)
		return (error());
	if (!(fd = open(av[1], O_RDONLY)))
		return (error());
	wall_check(fd, &wolf);
	if (hero_init(&wolf) == -1)
		return (error());
	initialize_mlx(&wolf);
	mlx_hook(wolf.win, 2, 1L << 0, key_hook1, &wolf);
	mlx_hook(wolf.win, 3, 1L << 1, key_hook2, &wolf);
	mlx_hook(wolf.win, 17, 0, close, NULL);
	mlx_loop_hook(wolf.mlx, key_hook3, &wolf);
	mlx_loop(wolf.mlx);
	return (0);
}
