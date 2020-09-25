/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:45:46 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 21:05:19 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		types(va_list ap, t_struct *f, int i)
{
	if (f->format[i] == 'd' || f->format[i] == 'i')
		return (decint(ap, f));
	else if (f->format[i] == 'c')
		return (c_char(ap, f));
	else if (f->format[i] == 's')
		return (string(ap, f));
	else if (f->format[i] == 'u')
		return (undecint(ap, f));
	else if (f->format[i] == '%')
		return (percent(f));
	else if (f->format[i] == 'x' || f->format[i] == 'X')
		return (unhexint(ap, f));
	else if (f->format[i] == 'p')
		return (pointer(ap, f));
	return (0);
}
