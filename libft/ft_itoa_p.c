/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:51:19 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/19 17:19:05 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_size_p_long(unsigned long long int n)
{
	unsigned int size;

	size = 1;
	while (n >= 16)
	{
		size++;
		n /= 16;
	}
	return (size);
}

char		*ft_itoa_p(unsigned long long int n)
{
	unsigned long long int		i;
	char						*res;
	char						*tab;

	i = ft_size_p_long(n);
	if (!(res = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (!(tab = ft_strdup("0123456789abcdef")))
		return (NULL);
	res[i--] = '\0';
	while (n >= 16)
	{
		res[i--] = tab[n % 16];
		n /= 16;
	}
	res[i] = tab[n];
	free(tab);
	return (res);
}
