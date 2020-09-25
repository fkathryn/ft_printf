/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 21:32:11 by fkathryn          #+#    #+#             */
/*   Updated: 2020/09/25 21:05:34 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		write_next_line(char **line, char **stat_buff, int fd)
{
	char	*r;
	int		i;

	i = 0;
	while ((stat_buff[fd])[i] != '\n' && (stat_buff[fd])[i] != '\0')
		i++;
	if ((stat_buff[fd])[i] == '\0')
	{
		*line = ft_strdup(stat_buff[fd]);
		free(stat_buff[fd]);
		stat_buff[fd] = 0;
		return (0);
	}
	if ((stat_buff[fd])[i] == '\n')
	{
		*line = ft_substr(stat_buff[fd], 0, i);
		r = ft_substr(stat_buff[fd], i + 1, ft_strlen(stat_buff[fd]));
		free(stat_buff[fd]);
		stat_buff[fd] = r;
	}
	return (1);
}

static int		check_strjoin(char **stat_buff, char *buff, int fd)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(stat_buff[fd], buff)))
	{
		free(stat_buff[fd]);
		free(buff);
		return (0);
	}
	free(stat_buff[fd]);
	stat_buff[fd] = tmp;
	return (1);
}

static int		check_next_line(int fd, char **line)
{
	char buff[1];

	if (!line || fd < 0)
		return (-1);
	if ((read(fd, buff, 0)) == -1)
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*stat_buff[10000];
	char			*buff;
	int				i;

	if ((i = check_next_line(fd, line)) < 0)
		return (-1);
	if (!(buff = (char *)malloc(10 + 1)))
		return (-1);
	if (stat_buff[fd] == NULL)
		stat_buff[fd] = ft_strdup("");
	while ((i = read(fd, buff, 10)) > 0)
	{
		buff[i] = '\0';
		if (!(check_strjoin(stat_buff, buff, fd)))
			return (-1);
		if (ft_strchr(stat_buff[fd], '\n'))
			break ;
	}
	free(buff);
	return (write_next_line(line, stat_buff, fd));
}
