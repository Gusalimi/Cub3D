/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:08:45 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:23:17 by fcherrie         ###   ########.fr       */
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
		if (temp[i] == ' ' || temp[i] == '1'
			|| temp[i] == '\n' || temp[i] == 'W'
			|| temp[i] == 'N' || temp[i] == 'S'
			|| temp[i] == 'E' || temp[i] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

static void	get_textures(char *temp, t_map *map)
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

char	*check_texture(int fd, char *temp, t_map *map)
{
	while (temp && check_start_map(temp) == 0)
	{
		get_textures(temp, map);
		free(temp);
		temp = get_next_line(fd);
	}
	if (map->img.no == NULL || map->img.so == NULL || map->img.we == NULL
		|| map->img.ea == NULL || map->img.c == NULL || map->img.f == NULL)
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
