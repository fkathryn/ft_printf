/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:37:20 by fkathryn          #+#    #+#             */
/*   Updated: 2020/09/05 12:18:30 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_before(va_list ap, t_struct *f)
{
	int res;

	res = 0;
	while (f->format[f->i] != '\0')
	{
		if (f->format[f->i] != '%')
			f->w += write(1, &f->format[f->i], 1);
		else
		{
			f->i++;
			f->i = parse(ap, f, f->i);
			if ((res = types(ap, f, f->i)) < 0)
				return (-1);
			zeroing_flags(f);
		}
		f->i++;
	}
	res += f->w;
	return (res);
}

void	zeroing_flags(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	f->flag = 0;
	f->flag_str = 0;
	f->width = 0;
	f->p = 0;
	f->precision = 0;
	f->n = 0;
	f->nu = 0;
	f->num = 0;
	f->lli = 0;
	f->c = 0;
	f->str = 0;
}

void	zeroing(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	f->flag = 0;
	f->flag_str = 0;
	f->width = 0;
	f->p = 0;
	f->precision = 0;
	f->i = 0;
	f->n = 0;
	f->s = 0;
	f->num = 0;
	f->lli = 0;
	f->nu = 0;
	f->c = 0;
	f->str = 0;
	f->len = 0;
	f->len_copy = 0;
	f->w = 0;
}

int		ft_printf(const char *format, ...)
{
	t_struct		*f;
	va_list			ap;
	int				result;

	if (!format)
		return (-1);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	if (!(f->format = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	zeroing(f);
	result = ft_before(ap, f);
	free(f->format);
	free(f);
	va_end(ap);
	return (result);
}
