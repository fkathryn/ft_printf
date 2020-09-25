/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:22:36 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 17:27:52 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int		ft_combo(char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		++i;
	}
	return (i);
}
