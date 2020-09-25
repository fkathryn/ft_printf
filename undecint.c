/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undecint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:05:18 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 16:17:37 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		undecint(va_list ap, t_struct *f)
{
	f->nu = va_arg(ap, unsigned int);
	if (!(f->str = ft_utoa(f->nu)))
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
	ft_print_dec(f);
	free(f->str);
	return (f->s);
}
