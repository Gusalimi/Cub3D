/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:38:57 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/26 23:47:49 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	if (a < 0)
		a = 0;
	if (a > 255)
		a = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	test_wall_n(t_map *map, int i)
{
	if ((int)map->p.r_x[i] % BLC >= 99)
		map->p.r_w[i] = 'W';
	else if ((int)map->p.r_x[i] % BLC <= 0)
		map->p.r_w[i] = 'E';
	else
		map->p.r_w[i] = 'N';
}

void	test_wall_e(t_map *map, int i)
{
	if ((int)map->p.r_y[i] % BLC >= 99)
		map->p.r_w[i] = 'N';
	else if ((int)map->p.r_y[i] % BLC <= 0)
		map->p.r_w[i] = 'S';
	else
		map->p.r_w[i] = 'E';
}

void	set_wall(t_map *map, int i, double rad)
{
	if (rad >= (M_PI / 4) && rad < ((3 * M_PI) / 4))
	{
		if ((int)map->p.r_x[i] % BLC >= 99)
			map->p.r_w[i] = 'W';
		else if ((int)map->p.r_x[i] % BLC <= 0)
			map->p.r_w[i] = 'E';
		else
			map->p.r_w[i] = 'S';
	}
	else if (rad >= ((3 * M_PI) / 4) && rad < ((5 * M_PI) / 4))
	{
		if ((int)map->p.r_y[i] % BLC >= 99)
			map->p.r_w[i] = 'N';
		else if ((int)map->p.r_y[i] % BLC <= 0)
			map->p.r_w[i] = 'S';
		else
			map->p.r_w[i] = 'W';
	}
	else if (rad >= ((5 * M_PI) / 4) && rad < ((7 * M_PI) / 4))
		test_wall_n(map, i);
	else
		test_wall_e(map, i);
}

void	set_radius(t_map *map, float rad, int i)
{
	float	f_x;
	float	f_y;

	while (++i != RAY)
	{
		f_x = map->p.p_x;
		f_y = map->p.p_y;
		while (map->map[(int) f_y / BLC][(int) f_x / BLC] != '1')
		{
			f_x += cosf(rad) * 1.5;
			f_y += sinf(rad) * 1.5;
		}
		map->p.r_y[i] = f_y;
		map->p.r_x[i] = f_x;
		set_wall(map, i, rad);
		rad += ((float) FOV / (float) RAY) * M_PI / 180;
	}
	good_wall(map);
}
