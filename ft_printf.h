/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 12:15:53 by fkathryn          #+#    #+#             */
/*   Updated: 2020/07/22 21:28:33 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct					s_struct
{
	char						*format;

	int							minus;
	int							zero;
	int							flag;
	int							flag_str;
	int							width;
	int							p;
	int							precision;

	int							i;
	int							n;
	int							s;
	int							num;
	unsigned long long int		lli;
	unsigned int				nu;
	unsigned char				c;
	char						*str;

	int							len;
	int							len_copy;

	int							w;
}								t_struct;

int								ft_printf(const char *format, ...);
void							zeroing(t_struct *f);
void							zeroing_flags(t_struct *f);
int								ft_before(va_list ap, t_struct *f);
int								types(va_list ap, t_struct *f, int i);

int								parse(va_list ap, t_struct *f, int i);
int								get_width(va_list ap, t_struct *f, int i);
int								get_precision(va_list ap, t_struct *f, int i);

int								ft_write(char *str, int len);
int								ft_combo(char c, int len);

int								decint(va_list ap, t_struct *f);
void							ft_print_dec(t_struct *f);
int								ft_flag_zero(t_struct *f);
void							ft_right_dec(t_struct *f);

int								string(va_list ap, t_struct *f);
void							ft_print_string(t_struct *f);

int								c_char(va_list ap, t_struct *f);

int								undecint(va_list ap, t_struct *f);

int								percent(t_struct *f);

int								unhexint(va_list ap, t_struct *f);
void							ft_print_hex(t_struct *f);

int								pointer(va_list ap, t_struct *f);
void							ft_print_pointer(t_struct *f);
void							ft_width_p(t_struct *f);

#endif
