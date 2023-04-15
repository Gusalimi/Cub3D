/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:44:55 by gsaile            #+#    #+#             */
/*   Updated: 2023/03/27 15:42:12 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_assets(char **s)
{
	char	*tmp;

	tmp = ft_strtrim(*s, " \n");
	if (!tmp)
		return (-1);
	free(*s);
	*s = tmp;
	return (0);
}

static int	has_alpha(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] < '0' || s[i] > '9')
			return (1);
	return (0);
}

static int	loop(char **split, int i, int tab[3])
{
	char	*tmp;
	int		j;

	tmp = ft_strtrim(split[i], " ");
	if (!tmp)
		return (1);
	j = 0;
	while (tmp[j] && tmp[j] == '0')
		j++;
	if (!tmp[j])
	{
		free(tmp);
		tab[i] = 0;
		return (0);
	}
	if (has_alpha(tmp + j) || ft_strlen(tmp + j) > 3
		|| (ft_strlen(tmp + j) == 3 && ft_strncmp(tmp + j, "255", 4) > 0))
	{
		free_tab(split);
		return (1);
	}
	tab[i] = ft_atoi(tmp + j);
	free(tmp);
	return (0);
}

int	get_colors(char *s, int tab[3])
{
	char	**split;
	int		i;

	split = ft_split(s, ',');
	if (!split)
		return (-1);
	i = -1;
	while (split[++i])
	{
		if (loop(split, i, tab) != 0)
			return (1);
	}
	free_tab(split);
	if (i != 3)
		return (1);
	return (0);
}
