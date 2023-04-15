/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:07:55 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:18:55 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cursorhook(double xpos, double ypos, void *param)
{
	static double	x;
	static double	y;
	t_map			*m;

	m = param;
	if (xpos < x)
		rotate_cam(m, 'A');
	else if (xpos > x)
		rotate_cam(m, 'D');
	x = xpos;
	y = ypos;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	float	f_x;
	float	f_y;
	t_map	*map;
	int		i;

	i = -1;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
	{
		map = param;
		f_x = map->p.p_x;
		f_y = map->p.p_y;
		while (++i <= 6 && map->map[(int) f_y / BLC][(int) f_x / BLC] != 'F'
			&& map->map[(int) f_y / BLC][(int) f_x / BLC] != 'O')
		{
			f_x += (SPEED * i * cosl(map->p.p_l * 3.14159265 / 180));
			f_y += (SPEED * i * sinl(map->p.p_l * 3.14159265 / 180));
		}
		if (map->map[(int) f_y / BLC][(int) f_x / BLC] == 'F')
			map->map[(int) f_y / BLC][(int) f_x / BLC] = 'O';
		else if (map->map[(int) f_y / BLC][(int) f_x / BLC] == 'O'
			&& map->map[(int) map->p.p_y / BLC][(int) map->p.p_x / BLC] != 'O')
			map->map[(int) f_y / BLC][(int) f_x / BLC] = 'F';
	}
}

void	anim(t_map *map)
{
	static int	i;

	if (i > 60)
		i = 0;
	if (i == 6)
		map->img.door_i = map->img.do1_i;
	if (i == 12)
		map->img.door_i = map->img.do2_i;
	if (i == 18)
		map->img.door_i = map->img.do3_i;
	if (i == 24)
		map->img.door_i = map->img.do4_i;
	if (i == 30)
		map->img.door_i = map->img.do5_i;
	if (i == 36)
		map->img.door_i = map->img.do6_i;
	if (i == 42)
		map->img.door_i = map->img.do7_i;
	if (i == 48)
		map->img.door_i = map->img.do8_i;
	i++;
}

void	hook(void *param)
{
	t_map	*m;

	m = param;
	display_minimap(m);
	anim(m);
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
	if (mlx_is_key_down(m->mlx, MLX_KEY_UP))
		m->p.j += 50;
	if (mlx_is_key_down(m->mlx, MLX_KEY_DOWN))
		m->p.j -= 50;
	set_radius(m, (m->p.p_l - FOV / 2) * M_PI / 180, -1);
	display_3d(m, (m->p.p_l - FOV / 2) * M_PI / 180);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = init_map(argc, argv);
	if (!map)
		return (1);
	if (get_assets_all(map) == 1)
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
	mlx_key_hook(map->mlx, &keyhook, map);
	mlx_loop_hook(map->mlx, &hook, map);
	mlx_cursor_hook(map->mlx, &cursorhook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	free_map(map);
	return (0);
}
