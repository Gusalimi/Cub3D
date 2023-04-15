/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:16:15 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/26 23:22:51 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint8_t	*get_add_ea(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.ea_i->height / hp) * p;
	y = (float) m->img.ea_i->width / BLC * ((int)m->p.r_y[i] % (int)BLC);
	pos = ((int) x * m->img.ea_i->width + (int) y);
	pi = &((m->img.ea_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_no(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.no_i->height / hp) * p;
	y = (float) m->img.no_i->width / BLC * ((int)m->p.r_x[i] % (int)BLC);
	pos = ((int) x * m->img.no_i->width + (int) y);
	pi = &((m->img.no_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_so(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.so_i->height / hp) * p;
	y = BLC - ((int)m->p.r_x[i] % (int)BLC);
	y = (float) m->img.so_i->width / BLC * (y);
	pos = ((int) x * m->img.so_i->width + (int) y);
	pi = &((m->img.so_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}

uint8_t	*get_add_we(t_map *m, float hp, float p, int i)
{
	int		pos;
	float	x;
	float	y;
	uint8_t	*pi;

	x = ((float)m->img.we_i->height / hp) * p;
	y = BLC - ((int)m->p.r_y[i] % (int)BLC);
	y = (float) m->img.we_i->width / BLC * (y);
	pos = ((int) x * m->img.we_i->width + (int) y);
	pi = &((m->img.we_i->pixels)[pos * sizeof(uint32_t)]);
	return (pi);
}
