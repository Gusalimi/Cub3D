/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:01:49 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 10:24:55 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	i2;
	char	*str;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	while (i < start && s[i] != '\0')
		i++;
	while (i2 < len && s[i + i2] != '\0')
		i2++;
	str = malloc((i2++ + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	i2 = 0;
	while (i2 < len && s[i] != '\0')
		str[i2++] = s[i++];
	str[i2] = '\0';
	return (str);
}
