/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:58:45 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/18 20:44:40 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int n)
{
	unsigned int size;

	size = 1;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_utoa(unsigned int n)
{
	unsigned int		i;
	char				*res;

	i = ft_size(n);
	if (!(res = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	res[i--] = '\0';
	while (n >= 10)
	{
		res[i--] = n % 10 + '0';
		n /= 10;
	}
	res[i] = n + '0';
	return (res);
}
