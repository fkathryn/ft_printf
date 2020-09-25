/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:09:10 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 16:26:35 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(va_list ap, t_struct *f, int i)
{
	while (f->format[i] == '-' || f->format[i] == '0')
	{
		if (f->format[i] == '-')
			f->minus = 1;
		else if (f->format[i] == '0')
			f->zero = 1;
		i++;
	}
	i = get_width(ap, f, i);
	if (f->format[i] == '.')
	{
		f->p = 1;
		i++;
		i = get_precision(ap, f, i);
	}
	if (f->minus || f->p)
		f->zero = 0;
	return (i);
}

int		get_width(va_list ap, t_struct *f, int i)
{
	if (f->format[i] == '*')
	{
		f->width = va_arg(ap, int);
		return (++i);
	}
	else if (f->format[i] >= '0' && f->format[i] <= '9')
	{
		f->width = ft_atoi(&(f->format[i]));
		while (f->format[i] >= '0' && f->format[i] <= '9')
			i++;
	}
	return (i);
}

int		get_precision(va_list ap, t_struct *f, int i)
{
	if (f->format[i] == '*')
	{
		f->precision = va_arg(ap, int);
		++i;
	}
	else if (f->format[i] >= '0' && f->format[i] <= '9')
	{
		f->precision = ft_atoi(&(f->format[i]));
		while (f->format[i] >= '0' && f->format[i] <= '9')
			i++;
	}
	if (f->precision < 0)
	{
		f->p = 0;
		f->precision = 0;
	}
	return (i);
}
