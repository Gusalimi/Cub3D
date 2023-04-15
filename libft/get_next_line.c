/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:54:07 by fcherrie          #+#    #+#             */
/*   Updated: 2023/01/02 09:26:15 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *p)
{
	free(p);
	return (NULL);
}

char	*ft_cut(char *buffer)
{
	int		i;
	int		i2;
	char	*newbuff;

	i = 0;
	i2 = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + i2] != '\0')
		i2++;
	newbuff = ft_calloc(i2 + 1, 1);
	if (!(newbuff))
		return (ft_free(buffer));
	i2 = -1;
	while (buffer[i + ++i2] != '\0')
		newbuff[i2] = buffer[i + i2];
	free(buffer);
	if (newbuff[0] == '\0')
		return (ft_free(newbuff));
	return (newbuff);
}

char	*ft_test_read(char *buff, char *buffer, int check)
{
	free(buff);
	if (check == -1)
		return (ft_free(buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_gnl(fd, buffer);
	if (!(buffer))
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	nextline = ft_nextline(buffer);
	if (!(nextline))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_cut(buffer);
	return (nextline);
}
