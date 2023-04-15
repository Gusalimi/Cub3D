/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:54:29 by fcherrie          #+#    #+#             */
/*   Updated: 2023/01/02 13:12:54 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_csize(const char *s, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (s[i] == '\0')
		return (1);
	if (c == '\0')
		return (2);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		size++;
	}
	if (s[i - 1] != c)
		size++;
	return (size);
}

static char	*ft_createstr(const char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0' && src[i] != c)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc((sizeof(char *) * ft_csize(s, c)));
	if (!(tab))
		return (NULL);
	while (*s == c && *s != '\0' && *s != (char) NULL)
		s++;
	while (*s != '\0' && *s != (char) NULL)
	{
		tab[i] = ft_createstr(s, c);
		if (!tab[i])
			return (ft_freetab(tab));
		s += ft_strlen(tab[i]);
		i++;
		if (*s != '\0')
		s++;
		while (*s == c && *s != '\0')
			s++;
	}
	tab[i] = 0;
	return (tab);
}
