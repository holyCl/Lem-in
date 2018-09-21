/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:09:45 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:14:07 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_ucharlen(wchar_t value)
{
	if (value <= 0x7F)
		return (1);
	else if (value <= 0x7FF)
		return (2);
	else if (value <= 0xE08080)
		return (3);
	else
		return (4);
}

int			ft_ustrlen(wchar_t *value)
{
	int		len;

	len = 0;
	while (*value)
	{
		if (*value <= 0x7F)
			len++;
		else if (*value <= 0x7FF)
			len += 2;
		else if (*value <= 0xE08080)
			len += 3;
		else
			len += 4;
		value++;
	}
	return (len);
}

int			ft_putwchar(wchar_t nmb)
{
	int		size;

	size = ft_ucharlen(nmb);
	if (size == 2 && MB_CUR_MAX > 1)
	{
		ft_putchar((nmb >> 6) + 0b11000000);
		ft_putchar((nmb & 0b111111) + 0b10000000);
	}
	else if (size == 3 && MB_CUR_MAX > 1)
	{
		ft_putchar((nmb >> 12) + 0b11100000);
		ft_putchar(((nmb >> 6) & 0b111111) + 0b10000000);
		ft_putchar((nmb & 0b111111) + 0b10000000);
	}
	else if (size == 4 && MB_CUR_MAX > 1)
	{
		ft_putchar((nmb >> 18) + 0b11110000);
		ft_putchar(((nmb >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((nmb >> 6) & 0b111111) + 0b10000000);
		ft_putchar((nmb & 0b111111) + 0b10000000);
	}
	else
		ft_putchar(nmb);
	return (size);
}

void		parsechars(t_conv *fl, wchar_t value, int *ret)
{
	if (fl->flags.minus == FALSE && fl->width > 0)
	{
		fl->flags.zeros == FALSE ?\
		pf_write(" ", 1, fl->width - 1) : pf_write("0", 1, fl->width - 1);
		*ret += fl->width - 1;
	}
	fl->lenght.len_l == FALSE ? ft_putchar(value) : ft_putwchar(value);
	*ret += (fl->lenght.len_l == FALSE) ? 1 : ft_ucharlen(value);
	if (fl->flags.minus == TRUE)
	{
		pf_write(" ", 1, fl->width - 1);
		*ret += fl->width - 1;
	}
}

int			ft_chars(t_conv *fl, va_list *arg_ptr)
{
	int		ret;
	wchar_t	value;

	ret = 0;
	if (fl->conv == '%')
		value = '%';
	else if (fl->lenght.len_l == TRUE)
		value = va_arg(*arg_ptr, wchar_t);
	else
		value = va_arg(*arg_ptr, int);
	parsechars(fl, value, &ret);
	return (ret);
}
