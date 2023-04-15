/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:49:38 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/27 12:14:23 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_do3(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do3 + ft_strlen(map->img.do3) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do3);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do3_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do3_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do2(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do2 + ft_strlen(map->img.do2) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do2);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do2_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do2_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do1(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do1 + ft_strlen(map->img.do1) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do1);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do1_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do1_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_door(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.door + ft_strlen(map->img.door) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.door);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.door_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.door_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}
