/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:25:41 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/24 13:15:08 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		parsestr2(t_conv *fl, int len, int *ret)
{
	if (fl->flags.minus != TRUE)
	{
		if (fl->width > len && fl->precision <= 0)
		{
			if (fl->precision == 0 && fl->dot != FALSE)
			{
				pf_write(" ", 1, fl->width);
				*ret += fl->width;
			}
			else
			{
				pf_write(" ", 1, fl->width - len);
				*ret += fl->width - len;
			}
		}
	}
	if (fl->flags.minus == FALSE && fl->width > len && fl->precision > 0)
	{
		pf_write(" ", 1, fl->width - len);
		*ret += fl->width - len;
	}
}

void		parsestr1(char *str, int len, t_conv *fl, int *ret)
{
	if (ft_strcmp("(null)", str) && fl->width == TRUE)
		str = "0";
	if (fl->flags.zeros == TRUE)
	{
		if (fl->width >= len)
		{
			pf_write("0", 1, fl->width - len);
			pf_write(str, len, 1);
			*ret += fl->width;
		}
	}
	else
	{
		parsestr2(fl, len, ret);
		fl->dot != -1 ? pf_write(str, len, 1) : 0;
		fl->dot != -1 ? *ret += len : 0;
	}
}
