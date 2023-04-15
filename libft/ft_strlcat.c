/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:22:27 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 12:02:30 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	tsize;

	if ((dst == NULL || src == NULL) && dstsize == 0)
		return (0);
	index = 0;
	tsize = 0;
	while (dst[tsize] != '\0')
		tsize++;
	while (tsize + index + 1 < dstsize && src[index] != '\0')
	{
		dst[tsize + index] = src[index];
		index++;
	}
	dst[tsize + index] = '\0';
	index = 0;
	while (src[index] != '\0')
			index++;
	if (dstsize == 0)
		return (index);
	if (dstsize < tsize)
		return (index + dstsize);
	return (tsize + index);
}
