/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:36:55 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/24 13:15:35 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_unsigned(t_conv *fl, int len, int *ret, char *value)
{
	if (fl->flags.minus == FALSE)
	{
		if (fl->flags.zeros == FALSE || (fl->dot == TRUE && fl->width > 0))
			pf_write(" ", 1, fl->width);
		else
			fl->dot == 0 ? pf_write("0", 1, fl->width) : 0;
		*ret += fl->width;
	}
	write_precision(fl, len, ret);
	if (*value != '0')
	{
		ft_putstr(value);
		*ret += ft_strlen(value);
	}
	else if (*value == '0' && fl->dot == FALSE)
	{
		ft_putstr(value);
		*ret += ft_strlen(value);
	}
	if (fl->flags.minus == TRUE)
	{
		pf_write(" ", 1, fl->width);
		*ret += fl->width;
	}
}

void	manage_unlen(t_conv *fl, int len, char *value)
{
	if (ft_strcmp(value, "0") == 0)
		return ;
	fl->precision > fl->width ? fl->width = 0 : 0;
	fl->precision < len ? fl->precision = 0 : 0;
	if (fl->width >= len)
	{
		if (fl->dot == TRUE && fl->precision > 0)
			fl->width -= fl->precision;
		else
			fl->width -= len;
	}
	else
		fl->width = 0;
}

int		fl_unsconv(t_conv *fl, va_list *arg_ptr, int base)
{
	char	*value;
	int		ret;
	int		len;

	ret = 0;
	value = (fl->conv == 'X') ?\
	cast_unsigned(arg_ptr, base, fl, 1) : cast_unsigned(arg_ptr, base, fl, 0);
	len = (int)ft_strlen(value);
	manage_unlen(fl, len, value);
	if ((fl->conv == 'X' || fl->conv == 'x' || fl->conv == 'o')\
	&& fl->flags.hash == TRUE)
		print_unsigned_hash(fl, len, &ret, value);
	else
		print_unsigned(fl, len, &ret, value);
	free(value);
	return (ret);
}
