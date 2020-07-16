/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:14:00 by jemendy           #+#    #+#             */
/*   Updated: 2020/06/03 15:22:31 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# define ESC 53

typedef struct		s_wolf
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			plane_x;
	double			plane_y;
	double			camera;
	double			ray_posx;
	double			ray_posy;
	double			ray_dirx;
	double			ray_diry;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			old_dir_x;
	double			old_plane_x;
	double			speed;
	double			boost;
	double			cam_wall;
	unsigned int	previous;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img_str;
	char			**tab;
	int				endian;
	int				sizeline;
	int				bpp;
	int				w;
	int				h;
	int				east;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				line_height;
	int				drawstart;
	int				drawend;
	int				l;
	int				x;
	int				color;
	int				south;
	int				xchecker;
	int				i;
	int				bou;
	int				shift;
	int				tap_126;
	int				tap_125;
	int				tap_123;
	int				tap_124;
}					t_wolf;

int					usage(void);
int					error(void);
void				wall_check(int fd, t_wolf *wolf);
void				closet(t_wolf *wolf);
int					check_map(int fd, t_wolf *wolf);
void				raicast2(t_wolf *wolf);
void				raicast1(t_wolf *wolf);
void				raycast(t_wolf *wolf);
void				start_pos(t_wolf *wolf);
int					draw_map(t_wolf *wolf);
int					hero_init(t_wolf *wolf);
void				pix_to_img(t_wolf *wolf, int color);
int					side(t_wolf *wolf);
void				recreation_img(t_wolf *wolf);
int					key_hook3(t_wolf *wolf);
int					key_hook1(int key, t_wolf *wolf);
int					key_hook2(int key, t_wolf *wolf);
void				key_126(t_wolf *wolf);
void				key_125(t_wolf *wolf);
void				key_123(t_wolf *wolf);
void				key_124(t_wolf *wolf);
void				shift_speed(t_wolf *wolf);
int					main(int ac, char **arv);

#endif
