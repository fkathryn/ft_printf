/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:06:18 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 18:47:17 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer(va_list ap, t_struct *f)
{
	f->lli = va_arg(ap, unsigned long long int);
	if (!(f->str = ft_itoa_p(f->lli)))
		return (-1);
	f->len = ft_strlen(f->str);
	f->len_copy = f->len + 2;
	if (f->p && f->str[f->n] == '0' && f->precision == 0)
	{
		if (f->width && !f->minus)
			f->s += ft_combo(' ', f->width - 2);
		f->s += ft_write("0x", 2);
		if (f->width && f->minus)
			f->s += ft_combo(' ', f->width - 2);
		free(f->str);
		return (f->s);
	}
	ft_print_pointer(f);
	free(f->str);
	return (f->s);
}

void	ft_print_pointer(t_struct *f)
{
	if (f->width > 0 && !f->minus && !f->zero)
	{
		ft_width_p(f);
		f->flag = 1;
	}
	f->s += ft_write("0x", 2);
	if (f->precision > f->len)
		f->s += ft_combo('0', f->precision - f->len);
	if (f->zero)
	{
		if (f->width > f->len_copy)
		{
			f->s += ft_combo('0', f->width - f->len_copy);
			f->flag = 1;
		}
	}
	f->s += ft_write(&f->str[f->n], f->len);
	f->width = (f->width > 0) ? f->width : f->width * (-1);
	if (f->flag == 0 && f->width)
		ft_width_p(f);
}

void	ft_width_p(t_struct *f)
{
	if (f->precision > f->len)
		f->s += ft_combo(' ', f->width - f->precision - 2);
	else
		f->s += ft_combo(' ', f->width - f->len_copy);
}
