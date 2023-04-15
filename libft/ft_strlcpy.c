/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:23:11 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 12:20:27 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	n;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	n = 0;
	while (src[n] != '\0')
		n++;
	index = 0;
	while (index + 1 < dstsize && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize != 0)
		dst[index] = '\0';
	return (n);
}
