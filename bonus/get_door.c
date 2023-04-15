/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:16:15 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 14:23:49 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint8_t	*get_add_dea(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.door_i->height / hp) * p;
	y = (float) m->img.door_i->width / BLC * ((int)m->p.r_y[i] % (int)BLC);
	pos = ((int) x * m->img.door_i->width + (int) y);
	pi = &((m->img.door_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_dno(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.door_i->height / hp) * p;
	y = (float) m->img.door_i->width / BLC * ((int)m->p.r_x[i] % (int)BLC);
	pos = ((int) x * m->img.door_i->width + (int) y);
	pi = &((m->img.door_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_dso(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.door_i->height / hp) * p;
	y = BLC - ((int)m->p.r_x[i] % (int)BLC);
	y = (float) m->img.door_i->width / BLC * (y);
	pos = ((int) x * m->img.door_i->width + (int) y);
	pi = &((m->img.door_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_dwe(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.door_i->height / hp) * p;
	y = BLC - ((int)m->p.r_y[i] % (int)BLC);
	y = (float) m->img.door_i->width / BLC * (y);
	pos = ((int) x * m->img.door_i->width + (int) y);
	pi = &((m->img.door_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}
