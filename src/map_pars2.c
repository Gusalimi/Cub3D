/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:02:21 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/27 16:26:19 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*init_map(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc != 2)
		return (dsp_error("Error\nUse like this :\n>_ ./cub3D [map]\n"));
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'
		|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
		return (dsp_error("Error\nNot a \".cub\" file\n"));
	map = ft_calloc(sizeof(t_map), 1);
	map->p.r_x = ft_calloc(sizeof(float), RAY);
	map->p.r_y = ft_calloc(sizeof(float), RAY);
	map->p.r_w = ft_calloc(sizeof(char), RAY);
	if (get_map(argv[1], map, NULL, NULL) == NULL)
	{
		free_map(map);
		return (NULL);
	}
	if (resize_map(map, -1, 0) || check_map(map) == NULL)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
