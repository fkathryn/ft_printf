/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unhexint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:04:22 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 18:47:32 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unhexint(va_list ap, t_struct *f)
{
	f->nu = va_arg(ap, unsigned int);
	if (!(f->str = ft_itoa_base(f->nu)))
		return (-1);
	f->len = ft_strlen(f->str);
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
	ft_print_hex(f);
	free(f->str);
	return (f->s);
}

void	ft_print_hex(t_struct *f)
{
	if (f->format[f->i] == 'x')
	{
		while (f->str[f->num] != '\0')
		{
			f->str[f->num] = ft_tolower(f->str[f->num]);
			f->num++;
		}
	}
	if (f->width > 0 && !f->minus && !f->zero)
	{
		ft_right_dec(f);
		f->flag = 1;
	}
	if ((f->precision - f->len) > 0)
		f->s += ft_combo('0', f->precision - f->len);
	f->s += ft_flag_zero(f) + ft_write(&f->str[f->n], f->len);
	f->width = (f->width > 0) ? f->width : f->width * (-1);
	if (f->flag == 0 && !f->zero)
		ft_right_dec(f);
}
