/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:15:33 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/04 21:20:19 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;
	int		index;

	index = 0;
	loc = NULL;
	while (s[index] != '\0')
	{
		if ((char)c == s[index])
			loc = (char *)&s[index];
		index++;
	}
	if ((char)c == '\0')
		loc = (char *)&s[index];
	if ((char)c != '\0' && loc == NULL)
		return (loc);
	return (loc);
}
