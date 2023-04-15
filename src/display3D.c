/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:59:08 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 00:16:50 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	get_color(t_map *m, int t)
{
	int	r;
	int	g;
	int	b;

	if (t == 0)
	{
		r = m->img.crgb[0];
		g = m->img.crgb[1];
		b = m->img.crgb[2];
		return (get_rgba(r, g, b, 255));
	}
	if (t == 1)
	{
		r = m->img.frgb[0];
		g = m->img.frgb[1];
		b = m->img.frgb[2];
		return (get_rgba(r, g, b, 255));
	}
	return (0);
}

uint32_t	get_pixel(t_map *m, int p, int i, int hp)
{
	int		r;
	int		g;
	int		b;
	uint8_t	*pixel;

	p -= ((LOOK) / 2 - (hp / 2));
	if (p == hp)
		p -= 1;
	if (m->p.r_w[i] == 'E')
		pixel = get_add_ea(m, hp, p, i);
	if (m->p.r_w[i] == 'N')
		pixel = get_add_no(m, hp, p, i);
	if (m->p.r_w[i] == 'S')
		pixel = get_add_so(m, hp, p, i);
	if (m->p.r_w[i] == 'W')
		pixel = get_add_we(m, hp, p, i);
	r = *(pixel++);
	g = *(pixel++);
	b = *(pixel++);
	return (get_rgba(r, g, b, 255));
}

void	print_pixel(t_map *map, int i, int p, float hp)
{
	if ((float)p < ((float)(LOOK) / 2 - (hp / 2)))
		mlx_put_pixel(map->img.render, i, p, get_color(map, 0));
	if (p > ((float)(LOOK) / 2))
		mlx_put_pixel(map->img.render, i, p, get_color(map, 1));
	if ((float) p > ((float)(LOOK) / 2 - (hp / 2))
		&& (float) p < ((float)(LOOK) / 2 + (hp / 2)))
		mlx_put_pixel(map->img.render, i, p, get_pixel(map, p, i, hp));
}

void	display_3d(t_map *map, float radc)
{
	int		i;
	float	hp;
	float	dist;
	int		p;

	i = -1;
	p = -1;
	mlx_delete_image(map->mlx, map->img.render);
	map->img.render = mlx_new_image(map->mlx, RAY, LOOK);
	while (++i != RAY)
	{
		dist = powl((map->p.p_x - map->p.r_x[i]), 2);
		dist += powl((map->p.p_y - map->p.r_y[i]), 2);
		hp = (BLC / sqrtl(dist) * (BLC * 6.5));
		hp = hp / (cosf((map->p.p_l * M_PI / 180) - radc));
		while (++p != LOOK)
		{
			print_pixel(map, i, p, hp);
		}
		p = -1;
		radc += ((float) FOV / (float) RAY) * M_PI / 180;
	}
	mlx_image_to_window(map->mlx, map->img.render, 0, 0);
}
