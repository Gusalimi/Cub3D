/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:08:45 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 12:39:05 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_start_map(char *temp)
{
	int	i;

	i = 0;
	if (temp == NULL)
		return (0);
	if (temp[0] == '\n')
		return (0);
	while (temp[i])
	{
		if (temp[i] == ' ' || temp[i] == '1' || temp[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*check_texture(int fd, char *temp, t_map *map)
{
	while (temp && check_start_map(temp) == 0)
	{
		look_for_door(map, temp);
		look_for_wall(map, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	if (map->img.no == NULL || map->img.so == NULL || map->img.we == NULL
		|| map->img.ea == NULL || map->img.c == NULL || map->img.f == NULL
		|| map->img.door == NULL)
	{
		dsp_error_read("Error\nCan not charge all wall's texture\n");
		return (NULL);
	}
	return (temp);
}

char	**get_map(char *file, t_map *map, char *line, char *temp)
{
	int		fd;	

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (dsp_error_read("Error\nCan't open the map file\n"));
	line = get_next_line(fd);
	if (line == NULL)
		return (dsp_error_read("Error\nEmpty map file\n"));
	line = check_texture(fd, line, map);
	if (line == NULL)
		return (NULL);
	temp = ft_calloc(sizeof(char), 1);
	while (temp != NULL)
	{
		line = ft_catline(temp, line);
		temp = get_next_line(fd);
	}
	if (has_nl(line))
		map->map = dsp_error("Error\nMap shouldn't contain empty line\n");
	else
		map->map = ft_split(line, '\n');
	free(line);
	free(temp);
	close(fd);
	return (map->map);
}

int	resize_map(t_map *map, int i, int size)
{
	char	**split;

	while (map->map[map->s_y])
	{
		size = ft_strlen(map->map[map->s_y]);
		if (size > map->s_x)
			map->s_x = size;
		(map->s_y)++;
	}
	split = ft_calloc(sizeof(char *), map->s_y + 1);
	size = -1;
	while (++size < map->s_y)
	{
		split[size] = ft_calloc(sizeof(char), map->s_x + 1);
		ft_strlcpy(split[size], map->map[size], map->s_x + 1);
		while (++i < map->s_x)
			if (split[size][i] == ' ' || split[size][i] == '\0')
				split[size][i] = ' ';
		i = -1;
	}
	free_tab(map->map);
	map->map = split;
	return (0);
}

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
	map->p.r_c = ft_calloc(sizeof(float), RAY);
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
