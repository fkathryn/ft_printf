/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:04:15 by fkathryn          #+#    #+#             */
/*   Updated: 2020/09/09 16:15:08 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*ss;
	size_t	i;

	i = 0;
	ss = (char *)s;
	while (ss[i] != '\0')
	{
		if (ss[i] == (char)c)
			return (&ss[i]);
		i++;
	}
	if ((char)c == '\0' && ss[i] == '\0')
		return (&ss[i]);
	return (NULL);
}
