/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:07:55 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:19:56 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	keyhook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W) && can_move(m, 'W'))
		move_player(m, 'W');
	if (mlx_is_key_down(m->mlx, MLX_KEY_S) && can_move(m, 'S'))
		move_player(m, 'S');
	if (mlx_is_key_down(m->mlx, MLX_KEY_D) && can_move(m, 'D'))
		move_player(m, 'D');
	if (mlx_is_key_down(m->mlx, MLX_KEY_A) && can_move(m, 'A'))
		move_player(m, 'A');
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		rotate_cam(m, 'A');
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		rotate_cam(m, 'D');
	set_radius(m, (m->p.p_l - FOV / 2) * M_PI / 180, -1);
	display_3d(m, (m->p.p_l - FOV / 2) * M_PI / 180);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = init_map(argc, argv);
	if (!map)
		return (1);
	if (get_assets(&map->img.no) == -1 || get_assets(&map->img.so) == -1
		|| get_assets(&map->img.we) == -1 || get_assets(&map->img.ea) == -1
		|| get_assets(&map->img.f) == -1 || get_assets(&map->img.c) == -1)
	{
		free_map(map);
		return (0);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map->mlx = mlx_init(RAY, LOOK, "Cub3D", true);
	if (init_textures(map) != 0)
	{
		free_map(map);
		return (0);
	}
	mlx_loop_hook(map->mlx, &keyhook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	free_map(map);
	return (0);
}
