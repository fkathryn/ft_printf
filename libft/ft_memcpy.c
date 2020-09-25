/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:56:57 by fkathryn          #+#    #+#             */
/*   Updated: 2020/05/17 22:57:06 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*scpy;

	if (dest == src)
		return (dest);
	str = (unsigned char *)dest;
	scpy = (unsigned char *)src;
	while (n-- > 0)
		*str++ = *scpy++;
	return (dest);
}
