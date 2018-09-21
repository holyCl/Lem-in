/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:25:50 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/21 16:39:58 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_precision(t_conv *fl, int widthlen, int *ret)
{
	if (fl->precision > 0)
		while (fl->precision-- - widthlen > 0)
		{
			ft_putchar('0');
			*ret += 1;
		}
}

void	write_zero1(t_conv *fl, int *ret, int widhlen)
{
	(fl->flags.minus == FALSE && fl->flags.zeros == TRUE\
		&& widhlen > fl->precision && fl->dot == FALSE) ? \
	pf_write("0", 1, fl->width) : 0;
	(fl->flags.minus == FALSE && fl->flags.zeros == TRUE\
		&& widhlen > fl->precision && fl->dot == FALSE) ? \
		(*ret += fl->width) : 0;
	fl->flags.zeros == TRUE && fl->precision == fl->width \
	&& fl->dot == TRUE\
	&& fl->precision > widhlen ? pf_write("0", 1, fl->width - widhlen) : 0;
	fl->flags.zeros == TRUE && fl->precision == fl->width \
	&& fl->dot == TRUE\
	&& fl->precision > widhlen ? *ret += fl->width - widhlen : 0;
}

void	write_zero_blank(t_conv *fl, int *ret, intmax_t arg, int widhlen)
{
	if (fl->width > 0)
	{
		if (fl->flags.minus == FALSE && fl->flags.zeros == FALSE\
		&& fl->flags.plus == FALSE)
		{
			if (arg < 0)
				fl->width--;
			fl->flags.blank == TRUE && fl->flags.zeros == TRUE\
			&& arg > 0 ? fl->width-- : 0;
		}
		(fl->flags.minus == TRUE && fl->flags.zeros == FALSE) ? \
		pf_write(" ", 1, fl->width - fl->temp) : 0;
		(fl->flags.minus == TRUE && fl->flags.zeros == FALSE) ? \
		(*ret += fl->width - fl->temp) : 0;
		(fl->flags.minus == FALSE && fl->flags.zeros == FALSE && fl->precision\
		> widhlen) ? pf_write("0", 1, fl->precision - widhlen) : 0;
		(fl->flags.minus == FALSE && fl->flags.zeros == FALSE\
		&& fl->precision > widhlen) ? (*ret += fl->precision - widhlen) : 0;
		write_zero1(fl, ret, widhlen);
	}
}

void	another_symb(char str, t_conv *fl, int *ret)
{
	if (fl->precision - 1 > 0)
		fl->width = fl->width - 1 - (fl->precision - 1);
	else if (fl->precision - 1 <= 0)
		fl->width = fl->width - 1;
	if (fl->flags.minus == FALSE && fl->flags.zeros == 0 && fl->width > 0)
		while (fl->width-- > 0)
		{
			ft_putchar(' ');
			*ret += 1;
		}
	if (fl->flags.minus > 0 || fl->flags.zeros > 0)
	{
		if (fl->flags.minus > 0)
		{
			ft_putwchar(str);
			*ret += 1;
		}
		while (fl->width-- > 0)
		{
			(fl->flags.minus > 0) ? ft_putchar(' ') : ft_putchar('0');
			*ret += 1;
		}
	}
	if (fl->flags.minus == FALSE)
		*ret += ft_putwchar(str);
}
