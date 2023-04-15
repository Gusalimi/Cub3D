/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:30:43 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 12:42:06 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	can_move2(t_map *map, char dir)
{
	float	f_x;
	float	f_y;

	if (dir == 'D')
	{
		f_x = map->p.p_x;
		f_x += (SPEED * 5 * cosl((map->p.p_l + 90) * 3.14159265 / 180));
		f_y = map->p.p_y;
		f_y += (SPEED * 5 * sinl((map->p.p_l + 90) * 3.14159265 / 180));
		if (map->map[(int) f_y / BLC][(int) f_x / BLC] == '1'
			|| map->map[(int) f_y / BLC][(int) f_x / BLC] == 'F')
			return (0);
	}
	if (dir == 'A')
	{
		f_x = map->p.p_x;
		f_x -= (SPEED * 5 * cosl((map->p.p_l + 90) * 3.14159265 / 180));
		f_y = map->p.p_y;
		f_y -= (SPEED * 5 * sinl((map->p.p_l + 90) * 3.14159265 / 180));
		if (map->map[(int) f_y / BLC][(int) f_x / BLC] == '1'
			|| map->map[(int) f_y / BLC][(int) f_x / BLC] == 'F')
			return (0);
	}
	return (1);
}

int	can_move(t_map *map, char dir)
{
	float	f_x;
	float	f_y;

	if (dir == 'W')
	{
		f_x = map->p.p_x;
		f_x += (SPEED * 5 * cosl(map->p.p_l * 3.14159265 / 180));
		f_y = map->p.p_y;
		f_y += (SPEED * 5 * sinl(map->p.p_l * 3.14159265 / 180));
		if (map->map[(int) f_y / BLC][(int) f_x / BLC] == '1'
			|| map->map[(int) f_y / BLC][(int) f_x / BLC] == 'F')
			return (0);
	}
	if (dir == 'S')
	{
		f_x = map->p.p_x;
		f_x -= (SPEED * 5 * cosl(map->p.p_l * 3.14159265 / 180));
		f_y = map->p.p_y;
		f_y -= (SPEED * 5 * sinl(map->p.p_l * 3.14159265 / 180));
		if (map->map[(int) f_y / BLC][(int) f_x / BLC] == '1'
			|| map->map[(int) f_y / BLC][(int) f_x / BLC] == 'F')
			return (0);
	}
	return (can_move2(map, dir));
}

void	rotate_cam(t_map *map, char dir)
{
	if (dir == 'D')
	{
		map->p.p_l += ROTATE_CAM;
		if (map->p.p_l >= 359)
			map->p.p_l = 0;
	}
	if (dir == 'A')
	{
		map->p.p_l -= ROTATE_CAM;
		if (map->p.p_l <= 1)
			map->p.p_l = 360;
	}
}

void	move_player(t_map *m, char dir)
{
	if (dir == 'W')
	{
		m->p.p_x += SPEED * cosl(m->p.p_l * 3.14159265 / 180);
		m->p.p_y += SPEED * sinl(m->p.p_l * 3.14159265 / 180);
	}
	if (dir == 'D')
	{
		m->p.p_x += SPEED * cosl((m->p.p_l + 90) * 3.14159265 / 180);
		m->p.p_y += SPEED * sinl((m->p.p_l + 90) * 3.14159265 / 180);
	}
	if (dir == 'A')
	{
		m->p.p_x -= SPEED * cosl((m->p.p_l + 90) * 3.14159265 / 180);
		m->p.p_y -= SPEED * sinl((m->p.p_l + 90) * 3.14159265 / 180);
	}
	if (dir == 'S')
	{
		m->p.p_x -= SPEED * cosl(m->p.p_l * 3.14159265 / 180);
		m->p.p_y -= SPEED * sinl(m->p.p_l * 3.14159265 / 180);
	}
}
