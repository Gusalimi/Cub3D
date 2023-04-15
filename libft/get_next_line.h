/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <fcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:56:50 by fcherrie          #+#    #+#             */
/*   Updated: 2023/01/02 09:28:20 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

char	*get_next_line(int fd);
int		ft_checkn(char *string);
char	*ft_read_gnl(int fd, char *buffer);
char	*ft_catbuf(char *dest, char *src);
char	*ft_cut(char *buffer);
char	*ft_nextline(char *buffer);
char	*ft_free(char *p);
char	*ft_test_read(char *buff, char *buffer, int check);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
#endif
