/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:18:50 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:16:55 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		j = (int)((1.0f / (sqrt(dist) / 70.0f)) * 50.0f);
		if (j + i >= RAY - 1 || j + i < 0)
			j = 0;
		if (map->p.r_w[i - 1] == map->p.r_w[i + j])
			map->p.r_w[i] = map->p.r_w[i - 1];
		i++;
	}
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
