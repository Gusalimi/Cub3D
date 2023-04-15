/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:28:16 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 12:20:56 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	if ((!haystack || !needle) && len == 0)
		return (0);
	i = 0;
	i2 = 0;
	if (needle[i] == '\0')
		return (&*(char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + i2] == needle[i2] && (i + i2) < len)
		{
			if (!(needle[i2 + 1]))
				return (&*(char *)(haystack + i));
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (0);
}
