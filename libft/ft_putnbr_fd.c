/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:15:15 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/07 11:29:09 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrecur(long int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * (-1);
	}
	ft_putnbrecur(nbr, fd);
}

static void	ft_putnbrecur(long int n, int fd)
{
	long int		r;
	long int		q;
	char			nb;

	r = n % 10;
	q = n / 10;
	nb = '0' + r;
	if (q > 0)
		ft_putnbrecur(q, fd);
	write(fd, &nb, 1);
}
