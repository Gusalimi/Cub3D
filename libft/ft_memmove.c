/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:49:51 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/05 15:54:39 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = 0;
	if (len == 0 || (!(src) && !(dst)))
		return (dst);
	if (src < dst)
	{
		len--;
		while (len > 0)
		{
			*(char *)(dst + len) = *(char *)(src + len);
			len--;
		}
		*(char *)(dst + len) = *(char *)(src + len);
	}
	else
	{
		while (index < len)
		{
		*(char *)(dst + index) = *(char *)(src + index);
		index++;
		}
	}
	return (dst);
}
