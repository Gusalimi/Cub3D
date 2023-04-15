/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:48:31 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 12:41:47 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_mmap(t_map *m, int x, int y, int blc)
{
	while (++y < blc * m->s_y)
	{
		while (++x < blc * m->s_x)
		{
			if (m->map[y / blc][x / blc] == '1'
				|| m->map[y / blc][x / blc] == 'F')
				mlx_put_pixel(m->img.mmap, x, y, get_rgba(0, 0, 0, 255));
			if (m->map[y / blc][x / blc] == '0'
				|| m->map[y / blc][x / blc] == 'E'
				|| m->map[y / blc][x / blc] == 'S'
				|| m->map[y / blc][x / blc] == 'N'
				|| m->map[y / blc][x / blc] == 'W'
				|| m->map[y / blc][x / blc] == 'O')
				mlx_put_pixel(m->img.mmap, x, y, get_rgba(255, 255, 255, 255));
			if (m->map[y / blc][x / blc] == ' ')
				mlx_put_pixel(m->img.mmap, x, y, get_rgba(0, 0, 0, 255));
			if (y / blc == (int)m->p.p_y / BLC
				&& x / blc == (int)m->p.p_x / BLC)
				mlx_put_pixel(m->img.mmap, x, y, get_rgba(255, 0, 0, 255));
		}
		x = -1;
	}
}

void	display_minimap(t_map *map)
{
	int	blc;

	blc = RAY / 3 / map->s_x;
	mlx_delete_image(map->mlx, map->img.mmap);
	map->img.mmap = mlx_new_image(map->mlx, blc * map->s_x, blc * map->s_y);
	set_mmap(map, -1, -1, blc);
	mlx_image_to_window(map->mlx, map->img.mmap, 0, 0);
	mlx_set_instance_depth(&map->img.mmap->instances[0], 10);
}
