/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:32:47 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:08:59 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	utf_zero_flag(t_conv *fl, int len, wchar_t *wstr, int *ret)
{
	pf_write("0", 1, fl->width - len);
	if (fl->dot == FALSE)
		while (*wstr)
		{
			ft_putwchar(*wstr);
			*ret += ft_ucharlen(*wstr++);
		}
	*ret += fl->width - len;
}

void	utf_parsestr1(wchar_t *wstr, int len, t_conv *fl, int *ret)
{
	if (fl->flags.zeros == TRUE && fl->width > len)
		utf_zero_flag(fl, len, wstr, ret);
	else
	{
		(fl->flags.minus != TRUE && len < fl->width) ?\
		pf_write(" ", 1, fl->width - len) : 0;
		(fl->flags.minus != TRUE && len < fl->width) ?\
		*ret += fl->width - len : 0;
		if (len > fl->width && fl->dot == TRUE)
		{
			fl->flags.zeros == FALSE \
			? pf_write(" ", 1, fl->width) : pf_write("0", 1, fl->width);
			*ret += fl->width;
		}
		if (fl->dot == FALSE)
			while (*wstr)
			{
				ft_putwchar(*wstr);
				*ret += ft_ucharlen(*wstr++);
			}
	}
}

void	utf_str1(t_conv *fl, wchar_t *wstr, int *ret)
{
	if (fl->flags.minus == FALSE)
	{
		if (fl->width > fl->precision)
		{
			fl->flags.zeros == TRUE ? \
			pf_write("0", 1, fl->width - fl->precision) :\
			pf_write(" ", 1, fl->width - fl->precision);
			*ret += fl->width - fl->precision;
		}
		while (fl->precision >= ft_ucharlen(*wstr))
		{
			fl->precision -= ft_putwchar(*wstr);
			*ret += ft_ucharlen(*wstr++);
		}
	}
	else
		while (fl->precision--)
		{
			ft_putwchar(*wstr);
			*ret += ft_ucharlen(*wstr++);
		}
}

void	utf_str(wchar_t *wstr, int len, t_conv *fl, int *ret)
{
	utf_parselenstr(fl, len, wstr);
	fl->flags.plus == TRUE && fl->flags.minus == TRUE \
	? fl->flags.plus = FALSE : 0;
	if (fl->precision > 0)
		utf_str1(fl, wstr, ret);
	else
		utf_parsestr1(wstr, len, fl, ret);
	fl->flags.minus == TRUE && len <= fl->width \
	? pf_write(" ", 1, fl->width - len) : 0;
	fl->flags.minus == TRUE && fl->width >= len ? *ret += fl->width - len : 0;
}
