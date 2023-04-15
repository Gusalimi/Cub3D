/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:31:30 by fcherrie          #+#    #+#             */
/*   Updated: 2023/01/02 09:28:18 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checkn(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}	
	return (0);
}

char	*ft_catbuf(char *dest, char *src)
{
	int		i;
	int		i2;
	char	*s;

	i = 0;
	i2 = 0;
	while (src[i])
		i++;
	while (dest[i2])
		i2++;
	s = ft_calloc(i + i2 + 1, 1);
	if (!(s))
		return (ft_free(src));
	i = 0;
	i2 = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	while (dest[i2])
		s[i++] = dest[i2++];
	free(src);
	return (s);
}

char	*ft_nextline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!(line))
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	return (line);
}

char	*ft_read_gnl(int fd, char *buffer)
{	
	char	*buff;
	int		check;

	check = 1;
	if (buffer == NULL)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!(buffer))
		return (NULL);
	while (ft_checkn(buffer) == 0 && check > 0)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!(buff))
			return (ft_free(buffer));
		check = read(fd, buff, BUFFER_SIZE);
		if (check <= 0)
			return (ft_test_read(buff, buffer, check));
		buffer = ft_catbuf(buff, buffer);
		free(buff);
		if (!(buffer))
			return (NULL);
	}	
	return (buffer);
}
