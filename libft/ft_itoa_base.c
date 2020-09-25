/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:43:54 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/20 12:43:58 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int n)
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

char		*ft_itoa_base(unsigned int n)
{
	unsigned int		i;
	char				*res;
	char				*tab;

	i = ft_size(n);
	if (!(res = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (!(tab = ft_strdup("0123456789ABCDEF")))
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
