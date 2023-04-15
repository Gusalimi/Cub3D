/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:46:25 by fcherrie          #+#    #+#             */
/*   Updated: 2022/11/06 21:42:46 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_csize(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_test_neg(long int n, char *str, int neg)
{
	if (n == 0)
		str[0] = '0';
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	int			neg;
	long int	nb;

	neg = 0;
	nb = n;
	size = ft_csize(n);
	if (n < 0)
	{
		neg = 1;
		nb *= -1;
	}
	str = malloc(sizeof(char) * size);
	if (!(str))
		return (NULL);
	str[size - 1] = '\0';
	while (nb != 0)
	{
		str[--size - 1] = '0' + (nb % 10);
		nb = nb / 10;
	}
	ft_test_neg(n, str, neg);
	return (str);
}
