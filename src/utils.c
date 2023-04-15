/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:25 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 15:37:24 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*dsp_error(char *text)
{
	ft_putstr_fd(text, 1);
	return (NULL);
}

char	**dsp_error_read(char *text)
{
	ft_putstr_fd(text, 1);
	return (NULL);
}

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	*free_map(t_map *map)
{
	if (map->map)
		free_tab(map->map);
	free(map->img.no);
	free(map->img.so);
	free(map->img.we);
	free(map->img.ea);
	free(map->img.f);
	free(map->img.c);
	free(map->p.r_y);
	free(map->p.r_w);
	free(map->p.r_x);
	free(map);
	return (NULL);
}

char	*ft_catline(char *dest, char *src)
{
	int		i;
	int		i2;
	char	*s;

	i = 0;
	i2 = 0;
	while (src[i])
		i++;
	while (dest[i2])
		i2++;
	s = ft_calloc(i + i2 + 1, sizeof(char));
	i = 0;
	i2 = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	while (dest[i2])
	s[i++] = dest[i2++];
	free(src);
	free(dest);
	return (s);
}
