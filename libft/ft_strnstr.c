/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:18:00 by fkathryn          #+#    #+#             */
/*   Updated: 2020/05/08 16:28:41 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	while (*big != '\0' && len-- >= l_len)
	{
		if (ft_strncmp((char*)big, (char *)little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
