/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:55:57 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:56:49 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_checkplus(t_conv *fl, int *ret)
{
	if ((fl->flags.plus == TRUE && fl->flags.minus == FALSE) || fl->arg < 0)
	{
		fl->arg > -1 ? pf_write("+", 1, 1) : pf_write("-", 1, 1);
		*ret += 1;
	}
}

void		check1(t_conv *fl, int *ret, int widhlen)
{
	if (fl->arg == 0 && fl->precision > 0)
	{
		pf_write(" ", 1, fl->width - fl->temp);
		*ret += fl->width - fl->temp;
	}
	else if (fl->arg == 0 && fl->precision == FALSE)
	{
		pf_write(" ", 1, fl->width + 1);
		*ret += fl->width + 1;
	}
	else if (fl->precision > widhlen)
	{
		pf_write(" ", 1, fl->width - fl->precision);
		*ret += fl->width - fl->precision;
		fl->temp = fl->precision;
	}
	else
	{
		fl->flags.plus == TRUE ? \
				pf_write(" ", 1, fl->width - 1) : pf_write(" ", 1, fl->width);
		*ret += (fl->flags.plus == TRUE) ? fl->width - 1 : fl->width;
	}
}

void		check(t_conv *fl, int *ret, int widhlen)
{
	if ((fl->flags.zeros == FALSE && fl->flags.minus == FALSE && fl->width > \
	0) || (fl->flags.minus == FALSE && fl->precision > 0 && fl->width > 0))
		if (fl->precision <= fl->width)
			check1(fl, ret, widhlen);
}
