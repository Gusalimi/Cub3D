/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:25:11 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 11:51:57 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	alloc = malloc((sizeof(char) * size) * count);
	if (!(alloc))
		return (NULL);
	while (i < (count * size))
		*(char *)(alloc + i++) = '\0';
	return (alloc);
}
