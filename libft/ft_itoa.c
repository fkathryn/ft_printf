/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:49:37 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/20 12:44:37 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_size(n);
	if (!(res = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	res[i--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		res[i--] = n % 10 + '0';
		n /= 10;
	}
	res[i] = n + '0';
	return (res);
}
