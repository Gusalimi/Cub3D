/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:49:38 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/27 12:14:20 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_do8(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do8 + ft_strlen(map->img.do8) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do8);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do8_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do8_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do7(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do7 + ft_strlen(map->img.do7) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do7);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do7_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do7_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do6(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do6 + ft_strlen(map->img.do6) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do6);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do6_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do6_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do5(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do5 + ft_strlen(map->img.do5) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do5);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do5_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do5_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_do4(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.do4 + ft_strlen(map->img.do4) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.do4);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load door texture.\n", 35));
		map->img.do4_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.do4_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}
