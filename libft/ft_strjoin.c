/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:57:52 by fkathryn          #+#    #+#             */
/*   Updated: 2020/09/09 16:16:07 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *c, const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		c[i] = s[i];
		++i;
	}
	return ((char *)c);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*cont;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(cont = (char *)malloc(sizeof(char) * (len1 + len2) + 1)))
		return (NULL);
	ft_copy(cont, s1);
	ft_copy(cont + len1, s2);
	cont[len1 + len2] = '\0';
	return (cont);
}
