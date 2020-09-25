/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:04:44 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 21:03:06 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string(va_list ap, t_struct *f)
{
	if (!(f->str = va_arg(ap, char *)))
	{
		f->flag_str = 1;
		if (!(f->str = ft_strdup("(null)")))
			return (-1);
	}
	f->len = ft_strlen(f->str);
	f->len_copy = f->len;
	if (f->p && f->precision < f->len)
		f->len = f->precision;
	ft_print_string(f);
	if (f->flag_str)
		free(f->str);
	return (f->s);
}

void	ft_print_string(t_struct *f)
{
	if ((!f->minus || f->width < 0) && !f->zero && f->width > f->len)
	{
		f->s += ft_combo(' ', f->width - f->len);
		f->flag = 1;
	}
	f->s += ft_flag_zero(f) + ft_write(f->str, f->len);
	f->width = ((f->width > 0) ? f->width : f->width * (-1));
	if (f->flag == 0 && f->width > f->len)
		f->s += ft_combo(' ', f->width - f->len);
}
