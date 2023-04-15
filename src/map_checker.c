/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:42:26 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 15:23:32 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_pos(t_map *map, int x, int y, int count)
{
	map->p.p_x = x * BLC;
	map->p.p_y = y * BLC;
	if (map->map[y][x] == 'N')
		map->p.p_l = 270;
	if (map->map[y][x] == 'E')
		map->p.p_l = 360;
	if (map->map[y][x] == 'S')
		map->p.p_l = 90;
	if (map->map[y][x] == 'W')
		map->p.p_l = 180;
	count++;
}

int	check_player(t_map *map, int x, int y, int count)
{
	while (++y < map->s_y)
	{
		while (++x < map->s_x)
		{
			if (map->map[y][x] != '1' && map->map[y][x] != ' '
				&& map->map[y][x] != 'W' && map->map[y][x] != 'N'
				&& map->map[y][x] != 'S' && map->map[y][x] != 'E'
				&& map->map[y][x] != '0')
			{
				dsp_error("Error\nCharacter a not recognise in the map\n");
				return (1);
			}
			if (map->map[y][x] == 'N' || map->map[y][x] == 'W'
					|| map->map[y][x] == 'S' || map->map[y][x] == 'E')
				set_pos(map, x, y, count++);
		}
		x = -1;
	}
	if (count != 1)
	{
		dsp_error("Error\nNeed just one player's position in the map\n");
		return (1);
	}
	return (0);
}

int	check_wall(t_map *map, int x, int y, char *str)
{
	while (++x < map->s_x)
		if (map->map[y][x] != '1' && map->map[y][x] != ' ')
			return (1);
	x = -1;
	while (++y < map->s_y - 1)
	{
		while (++x < map->s_x)
		{
			str = ft_strtrim(map->map[y], " ");
			if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
			{
				free(str);
				return (1);
			}
			free(str);
			if ((map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
				&& (map->map[y][x] != '1' && map->map[y][x] != ' '))
				return (1);
		}
		x = -1;
	}
	while (++x < map->s_x)
		if (map->map[y][x] != '1' && map->map[y][x] != ' ')
			return (1);
	return (0);
}

void	*check_map(t_map *map)
{
	if (check_wall(map, -1, 0, NULL))
		return (dsp_error("Error\nThe map is not closed by wall\n"));
	if (check_player(map, -1, -1, 0))
		return (NULL);
	return (map);
}
