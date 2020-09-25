/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:05:56 by fkathryn          #+#    #+#             */
/*   Updated: 2020/05/08 14:28:09 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	int		len;

	len = ft_strlen((char *)s);
	ss = (char *)s + len;
	while (len >= 0)
	{
		if (*ss == c)
			return (ss);
		len--;
		ss--;
	}
	return (0);
}
