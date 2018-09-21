/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:26:39 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:25:01 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	parselenstr(t_conv *fl, int len)
{
	if (len > fl->width && fl->width + fl->precision < len)
		fl->width = 0;
	if (fl->precision > fl->width && fl->precision > len)
		fl->precision = -1;
	if (fl->dot == TRUE && fl->precision == FALSE)
		fl->dot = -1;
	if (fl->precision > 0 && fl->precision >= len && fl->dot == FALSE)
		fl->precision = 0;
}

void	flags_str(t_conv *fl, int len, int *ret, char *str)
{
	if (fl->flags.minus == FALSE)
	{
		fl->width < 0 ? pf_write(" ", 1, fl->width + fl->precision) : 0;
		fl->width < 0 ? (*ret += fl->width + fl->precision) : 0;
		fl->width > fl->precision && len > fl->precision && fl->dot == TRUE\
			? pf_write(" ", 1, fl->width - fl->precision) : 0;
		fl->width > fl->precision && len > fl->precision && fl->dot == TRUE\
			? *ret += fl->width - fl->precision : 0;
		fl->width > fl->precision && len < fl->precision && fl->dot == TRUE\
			? pf_write(" ", 1, fl->width - len) : 0;
		fl->width > fl->precision && len < fl->precision && fl->dot == TRUE\
			? *ret += fl->width - len : 0;
		(fl->precision >= len) ?\
			pf_write(str, len, 1) : pf_write(str, fl->precision, 1);
		*ret += (fl->precision >= len) ? len : fl->precision;
	}
	else
	{
		(fl->precision >= len) ?\
			pf_write(str, len, 1) : pf_write(str, fl->precision, 1);
		*ret += (fl->precision >= len) ? len : fl->precision;
	}
}

void	ft_parsestr(char *str, int len, t_conv *fl, int *ret)
{
	fl->flags.plus == TRUE && fl->flags.minus == TRUE\
	? fl->flags.plus = FALSE : 0;
	if (fl->precision > 0)
		flags_str(fl, len, ret, str);
	else
		parsestr1(str, len, fl, ret);
	fl->flags.minus == TRUE && fl->precision == -1 ?\
	pf_write(" ", 1, fl->width) : 0;
	fl->flags.minus == TRUE && fl->precision == -1 ? *ret += fl->width : 0;
	if (fl->precision > len || fl->dot == FALSE)
	{
		fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width\
		? pf_write(" ", 1, fl->width - len) : 0;
		fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width\
		? *ret += fl->width - len : 0;
	}
	else
	{
		fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width\
		? pf_write(" ", 1, fl->width - fl->precision) : 0;
		fl->flags.minus == TRUE && fl->precision >= 0 && len <= fl->width\
		? *ret += fl->width - fl->precision : 0;
	}
}

int		lentype(t_conv *fl, va_list *arg_ptr, char *str, wchar_t *wstr)
{
	int	ret;
	int	len;

	ret = 0;
	if (fl->lenght.len_l == FALSE)
	{
		str = va_arg(*arg_ptr, char *);
		if (str == NULL && fl->width == 0)
			str = "(null)";
		else if (str == NULL && fl->width > 0)
			str = "0";
		len = (int)ft_strlen(str);
		parselenstr(fl, len);
		ft_parsestr(str, len, fl, &ret);
	}
	else
	{
		wstr = va_arg(*arg_ptr, wchar_t *);
		wstr == NULL ? wstr = L"(null)" : 0;
		len = ft_ustrlen(wstr);
		utf_str(wstr, len, fl, &ret);
	}
	return (ret);
}

int		ft_str(t_conv *fl, va_list *arg_ptr)
{
	int		ret;
	char	*str;
	wchar_t	*wstr;

	str = NULL;
	wstr = NULL;
	ret = 0;
	ret += lentype(fl, arg_ptr, str, wstr);
	return (ret);
}
