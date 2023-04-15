/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:49:38 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/27 15:36:09 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_north(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.no + ft_strlen(map->img.no) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.no);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load North texture.\n", 35));
		map->img.no_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.no_i)
			return (write(2, "Error\nCouldn't load North texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid North texture path.\n", 34));
	return (0);
}

static int	init_south(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.so + ft_strlen(map->img.so) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.so);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load South texture.\n", 35));
		map->img.so_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.so_i)
			return (write(2, "Error\nCouldn't load South texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid South texture path.\n", 34));
	return (0);
}

static int	init_west(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.we + ft_strlen(map->img.we) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.we);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load West texture.\n", 35));
		map->img.we_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.we_i)
			return (write(2, "Error\nCouldn't load West texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid West texture path.\n", 34));
	return (0);
}

static int	init_east(t_map *map, mlx_texture_t *tmp_t)
{
	if (ft_strncmp(map->img.ea + ft_strlen(map->img.ea) - 3, "png", 3) == 0)
	{
		tmp_t = mlx_load_png(map->img.ea);
		if (!tmp_t)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
		map->img.ea_i = mlx_texture_to_image(map->mlx, tmp_t);
		mlx_delete_texture(tmp_t);
		if (!map->img.ea_i)
			return (write(2, "Error\nCouldn't load East texture.\n", 35));
	}
	else
		return (write(2, "Error\nInvalid East texture path.\n", 34));
	return (0);
}

int	init_textures(t_map *map)
{
	int	tmp;

	tmp = get_colors(map->img.f, map->img.frgb);
	if (tmp > 0)
		return (write(2,
				"Colors must be 3 comma-separated values between 0 and 255.\n",
				59));
	else if (tmp == -1)
		return (-1);
	tmp = get_colors(map->img.c, map->img.crgb);
	if (tmp > 0)
		return (write(2,
				"Colors must be 3 comma-separated values between 0 and 255.\n",
				59));
	else if (tmp == -1)
		return (-1);
	return (init_north(map, NULL) != 0
		|| init_south(map, NULL) != 0
		|| init_west(map, NULL) != 0
		|| init_east(map, NULL) != 0);
}
