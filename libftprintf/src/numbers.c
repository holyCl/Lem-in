/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:14:37 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/27 15:59:34 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_pf2(t_conv *fl, int widhlen, int *ret, char *value)
{
	if (fl->precision == 0 && fl->arg == 0 && fl->width == 0)
	{
		write_precision(fl, widhlen, ret);
		ft_putstr(value);
		*ret += widhlen;
		return ;
	}
	fl->width >= fl->precision && widhlen > fl->width ? \
	write_precision(fl, widhlen, ret) : 0;
	(fl->width <= 0 && fl->precision > 0 && fl->flags.minus == FALSE) > 0 ? \
	write_precision(fl, widhlen, ret) : 0;
	(fl->flags.plus == FALSE && fl->precision < widhlen) ? \
	write_precision(fl, widhlen, ret) : 0;
	if (fl->flags.minus == FALSE)
	{
		ft_putstr(value);
		*ret += widhlen;
	}
	else
	{
		(widhlen <= fl->width && fl->flags.plus != TRUE) ?\
		pf_write(" ", 1, fl->width - fl->temp) : 0;
		(widhlen <= fl->width && fl->flags.plus != TRUE) ?\
		*ret += fl->width - fl->temp : 0;
	}
}

void		ft_pf1(t_conv *fl, int widhlen, int *ret, char *value)
{
	pf_checkplus(fl, ret);
	if (fl->arg == 0)
		if (fl->dot == TRUE && fl->precision <= 0)
			return ;
	fl->flags.minus == TRUE ? write_precision(fl, widhlen, ret) : 0;
	fl->flags.minus == TRUE ? ft_putstr(value) : 0;
	fl->flags.minus == TRUE ? *ret += widhlen : 0;
	fl->flags.plus == TRUE && fl->flags.zeros == TRUE ? \
	write_zero_blank(fl, ret, fl->arg, widhlen) : 0;
	fl->flags.plus == TRUE && fl->flags.zeros == FALSE ? \
	write_zero_blank(fl, ret, fl->arg, widhlen) : 0;
	fl->flags.plus == FALSE && fl->flags.zeros == FALSE && fl->precision > \
	widhlen ? write_zero_blank(fl, ret, fl->arg, widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.plus == FALSE ? \
	write_zero_blank(fl, ret, fl->arg, widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.minus == FALSE \
	&& fl->precision < fl->width && widhlen <= fl->precision
	? pf_write("0", 1, fl->precision - widhlen) : 0;
	fl->flags.zeros == TRUE && fl->flags.minus == FALSE \
	&& fl->precision < fl->width && widhlen <= fl->precision
	? *ret += fl->precision - widhlen : 0;
	ft_pf2(fl, widhlen, ret, value);
}

void		ft_pf(t_conv *fl, int widhlen, int *ret, char *value)
{
	if (fl->flags.blank == TRUE && fl->flags.plus == FALSE)
	{
		fl->arg >= 0 ? ft_putchar(' ') : 0;
		fl->arg >= 0 ? *ret += 1 : 0;
	}
	(fl->flags.blank == TRUE || fl->arg < 0 || fl->flags.plus == TRUE) \
	&& fl->width >= 1 ? fl->width-- : 0;
	fl->flags.plus == TRUE && fl->flags.minus == TRUE && fl->arg > -1 ? \
	pf_write("+", 1, 1) : 0;
	fl->flags.plus == TRUE && fl->flags.minus == TRUE ? *ret += 1 : 0;
	check(fl, ret, widhlen);
	if (fl->flags.zeros == TRUE && fl->dot == TRUE && \
	fl->precision == FALSE && fl->width > 0)
	{
		pf_write(" ", 1, fl->width);
		*ret += fl->width;
	}
	if (fl->flags.plus == TRUE && fl->flags.zeros == TRUE \
	&& fl->width < fl->precision)
	{
		pf_write(" ", 1, fl->width);
		*ret += fl->width;
	}
	ft_pf1(fl, widhlen, ret, value);
}

void		ft_parsewidth_numb(t_conv *fl, int widhlen)
{
	if (fl->width == 0 && fl->precision > 0)
	{
		if (fl->precision - widhlen)
			return ;
	}
	if (fl->precision > widhlen)
	{
		fl->temp = fl->precision;
		if (fl->width < fl->precision)
			fl->width = 0;
	}
	else if (fl->precision <= widhlen && fl->dot == TRUE)
	{
		if (widhlen <= fl->width)
			fl->width = fl->width - widhlen;
		else
			fl->width = 0;
		fl->precision = 0;
	}
	if (fl->dot == FALSE && fl->width > widhlen)
		fl->width -= widhlen;
	else if (fl->dot == FALSE && fl->width <= widhlen)
		fl->width = 0;
}

int			ft_numbers(t_conv *fl, va_list *arg_ptr)
{
	intmax_t	narg;
	int			len;
	int			ret;
	char		*value;

	ret = 0;
	len = 0;
	fl->arg = ft_parse_sign(fl, arg_ptr);
	narg = (fl->arg < 0) ? fl->arg * -1 : fl->arg * 1;
	value = ft_itoa_base(narg, 10, 0);
	len += ft_strlen(value);
	ft_parsewidth_numb(fl, len);
	ft_pf(fl, len, &ret, value);
	free(value);
	return (ret);
}
