/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:18:50 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:45:18 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	look_for_door(t_map *map, char *temp)
{
	char	*tmp;

	tmp = ft_strtrim(temp, " ");
	if (ft_strncmp(tmp, "D8 ", 3) == 0)
		map->img.do8 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D7 ", 3) == 0)
		map->img.do7 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D6 ", 3) == 0)
		map->img.do6 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D5 ", 3) == 0)
		map->img.do5 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D4 ", 3) == 0)
		map->img.do4 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D3 ", 3) == 0)
		map->img.do3 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D2 ", 3) == 0)
		map->img.do2 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "D1 ", 3) == 0)
		map->img.do1 = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "DO ", 3) == 0)
		map->img.door = ft_strdup(tmp + 3);
	free(tmp);
}

void	look_for_wall(t_map *map, char *temp)
{
	char	*tmp;

	tmp = ft_strtrim(temp, " ");
	if (ft_strncmp(tmp, "NO ", 3) == 0)
		map->img.no = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "F ", 2) == 0)
		map->img.f = ft_strdup(tmp + 2);
	if (ft_strncmp(tmp, "C ", 2) == 0)
		map->img.c = ft_strdup(tmp + 2);
	if (ft_strncmp(tmp, "SO ", 3) == 0)
		map->img.so = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "WE ", 3) == 0)
		map->img.we = ft_strdup(tmp + 3);
	if (ft_strncmp(tmp, "EA ", 3) == 0)
		map->img.ea = ft_strdup(tmp + 3);
	free(tmp);
}

void	good_wall(t_map *map)
{
	int		i;
	float	dist;
	int		j;

	i = 1 ;
	while (i < RAY)
	{
		dist = pow(map->p.r_x[i] - map->p.p_x, 2);
		dist += pow(map->p.r_y[i] - map->p.p_y, 2);
		dist = (int)((1 / (sqrt(dist) / 70)) * 50);
		j = dist;
		if (j + i >= RAY || j + i < 0)
			j = 0;
		if (map->p.r_w[i - 1] == map->p.r_w[i + j])
			map->p.r_w[i] = map->p.r_w[i - 1];
		i++;
	}
}

int	get_assets_all(t_map *map)
{
	if (get_assets(&map->img.no) == -1 || get_assets(&map->img.so) == -1
		|| get_assets(&map->img.we) == -1 || get_assets(&map->img.ea) == -1
		|| get_assets(&map->img.f) == -1 || get_assets(&map->img.c) == -1
		|| get_assets(&map->img.door) == -1 || get_assets(&map->img.do1) == -1
		|| get_assets(&map->img.do2) == -1 || get_assets(&map->img.do3) == -1
		|| get_assets(&map->img.do4) == -1 || get_assets(&map->img.do5) == -1
		|| get_assets(&map->img.do6) == -1 || get_assets(&map->img.do7) == -1
		|| get_assets(&map->img.do8) == -1)
		return (1);
	return (0);
}

int	has_nl(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
