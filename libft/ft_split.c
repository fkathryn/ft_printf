/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:52:55 by fkathryn          #+#    #+#             */
/*   Updated: 2020/05/18 13:52:14 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t words;
	size_t i;

	words = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++words;
		++i;
	}
	return (words);
}

static size_t	ft_len(char const *s, char c)
{
	size_t l;

	l = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		l++;
	}
	return (l);
}

static void		*ft_free(char **result, size_t j)
{
	size_t i;

	i = 0;
	while (i < j)
	{
		free(result[j]);
		i++;
		j--;
	}
	free(result);
	return (0);
}

static char		**ft_res(char **result, char const *s, char c, size_t words)
{
	size_t len;
	size_t j;
	size_t k;

	len = 0;
	j = 0;
	while (j < words)
	{
		while (*s == c)
			s++;
		len = ft_len(s, c);
		if (!(result[j] = (char *)ft_calloc(len + 1, sizeof(char))))
			return (ft_free(result, j));
		k = 0;
		while (k < len)
			result[j][k++] = *s++;
		result[j][k] = '\0';
		++j;
	}
	result[j] = NULL;
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (0);
	words = ft_words(s, c);
	if (!(array = (char **)ft_calloc(words + 1, sizeof(char *))))
		return (0);
	return (ft_res(array, s, c, words));
}
