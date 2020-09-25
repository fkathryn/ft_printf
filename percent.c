/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:06:42 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 17:12:18 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(t_struct *f)
{
	f->c = 37;
	f->len = 1;
	if (f->width > 0 && !f->minus && !f->zero)
	{
		ft_right_dec(f);
		f->flag = 1;
	}
	if (f->precision > f->len)
		f->s += ft_combo('0', f->precision - f->len);
	f->s += ft_flag_zero(f) + ft_write((char *)(&f->c), f->len);
	f->width = ((f->width > 0) ? f->width : f->width * (-1));
	if (f->flag == 0 && f->width)
		ft_right_dec(f);
	return (f->s);
}
