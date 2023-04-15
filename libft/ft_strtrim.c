/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:37:46 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 11:15:35 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		i2;
	int		size;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	i2 = 0;
	if (*s1 != '\0')
	{
		while (ft_checkset(s1[i], set) == 1)
			i++;
		size = ft_strlen(s1) - i;
		while (ft_checkset(s1[(size + i) - 1], set) == 1)
			size--;
	}
	if (s1[i] == '\0')
		size = 0;
	str = ft_calloc((size + 1), sizeof(char));
	if (!(str))
		return (NULL);
	while (i2 < size)
		str[i2++] = s1[i++];
	return (str);
}
