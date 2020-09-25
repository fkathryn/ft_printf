/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:05:28 by fkathryn          #+#    #+#             */
/*   Updated: 2020/09/09 16:14:28 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		return (ft_strdup(""));
	if (!(p = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0 && s[start] != '\0')
	{
		p[i] = s[start];
		start++;
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}
