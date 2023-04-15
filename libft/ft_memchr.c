/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:28:03 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/04 20:40:37 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*loc;
	size_t	index;

	index = 0;
	while (*(unsigned char *)(s + index) != (unsigned char) c
			&& index + 1 < n)
		index++;
	if ((unsigned char) c != *(unsigned char *)(s + index) || n == 0)
	{
		loc = NULL;
		return (loc);
	}
	loc = (void *)&s[index];
	return (loc);
}
