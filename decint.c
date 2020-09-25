/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:03:44 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 18:44:53 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		decint(va_list ap, t_struct *f)
{
	f->num = va_arg(ap, int);
	if (!(f->str = ft_itoa(f->num)))
		return (-1);
	f->len = ft_strlen((f->str));
	f->len_copy = f->len;
	if (f->p && f->str[f->n] == '0' && f->precision == 0 && !f->width)
	{
		free(f->str);
		return (0);
	}
	if (f->p && f->str[f->n] == '0' && f->precision == 0 && f->width)
	{
		f->s += ft_combo(' ', f->width);
		free(f->str);
		return (f->s);
	}
	if (f->str[f->n] == '-')
		f->precision++;
	ft_print_dec(f);
	free(f->str);
	return (f->s);
}

void	ft_print_dec(t_struct *f)
{
	if (f->width > 0 && !f->minus && !f->zero)
	{
		ft_right_dec(f);
		f->flag = 1;
	}
	if (f->str[f->n] == '-')
	{
		f->s += ft_combo('-', 1);
		f->n++;
		f->len_copy--;
	}
	if ((f->precision - f->len) > 0)
		f->s += ft_combo('0', f->precision - f->len);
	f->s += ft_flag_zero(f) + ft_write(&f->str[f->n], f->len_copy);
	f->width = (f->width > 0) ? f->width : f->width * (-1);
	if (f->flag == 0 && f->width)
		ft_right_dec(f);
}

int		ft_flag_zero(t_struct *f)
{
	int i;

	i = 0;
	if (f->zero && !f->minus)
	{
		if (f->width > f->len)
		{
			i = ft_combo('0', f->width - f->len);
			f->flag = 1;
		}
	}
	return (i);
}

void	ft_right_dec(t_struct *f)
{
	if (f->precision > f->len)
		f->s += ft_combo(' ', f->width - f->precision);
	else
		f->s += ft_combo(' ', f->width - f->len);
}
