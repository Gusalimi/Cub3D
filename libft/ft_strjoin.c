/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:28:58 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 10:27:06 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * i + 1);
	if (!(str))
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i2] != '\0')
		str[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2] != '\0')
		str[i++] = s2[i2++];
	str[i] = '\0';
	return (str);
}
