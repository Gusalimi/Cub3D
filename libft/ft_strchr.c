/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:07 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/04 22:19:47 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*loc;
	int		index;

	index = 0;
	while (s[index] != (char)c && s[index] != '\0')
		index++;
	if ((char)c != '\0' && (char)c != s[index])
	{
		loc = NULL;
		return (loc);
	}
	loc = (char *)&s[index];
	return (loc);
}
