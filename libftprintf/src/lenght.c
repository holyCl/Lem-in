/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:57:16 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:13:14 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

intmax_t	ft_parse_sign(t_conv *fl, va_list *arg_ptr)
{
	intmax_t	nbr;

	if (fl->lenght.len_z == 1)
		nbr = va_arg(*arg_ptr, ssize_t);
	else if (fl->lenght.len_j == 1)
		nbr = (intmax_t)va_arg(*arg_ptr, intmax_t);
	else if (fl->lenght.len_l > 1)
		nbr = va_arg(*arg_ptr, long long);
	else if (fl->lenght.len_l == 1)
		nbr = va_arg(*arg_ptr, long);
	else if (fl->lenght.len_h == 1)
		nbr = (short int)va_arg(*arg_ptr, int);
	else if (fl->lenght.len_h > 1)
		nbr = (signed char)va_arg(*arg_ptr, int);
	else
		nbr = (int)va_arg(*arg_ptr, long long int);
	return (nbr);
}

char		*cast_unsigned(va_list *arg_ptr, int base, t_conv *fl, int cap)
{
	if (fl->lenght.len_z == TRUE)
		return (ft_itoa_base(va_arg(*arg_ptr, size_t), base, cap));
	else if (fl->lenght.len_j == TRUE)
		return (ft_itoa_base(va_arg(*arg_ptr, uintmax_t), base, cap));
	else if (fl->lenght.len_l > TRUE)
		return (ft_itoa_base(va_arg(*arg_ptr, unsigned long long), base, cap));
	else if (fl->lenght.len_l == TRUE)
		return (ft_itoa_base(va_arg(*arg_ptr, unsigned long), base, cap));
	else if (fl->lenght.len_h == TRUE)
		return (ft_itoa_base((unsigned short)va_arg(*arg_ptr, int), base, cap));
	else if (fl->lenght.len_h > TRUE)
		return (ft_itoa_base((unsigned char)va_arg(*arg_ptr, int), base, cap));
	else
		return (ft_itoa_base(va_arg(*arg_ptr, unsigned int), base, cap));
}

void		ft_findlp1(char *str, t_conv *fl, size_t *pos, int len)
{
	if (fl->dot == 0)
	{
		fl->width = 0;
		while (ft_isdigit(str[len]) == 1)
		{
			fl->width = fl->width * 10 + str[len] - '0';
			len++;
		}
		*pos += len - 1;
		return ;
	}
	else
		while (ft_isdigit(str[len]) == 1)
		{
			fl->precision = fl->precision * 10 + str[len] - '0';
			len++;
		}
	*pos += len - 1;
}

void		ft_findlp(char *str, t_conv *fl, size_t *pos)
{
	int		len;

	len = 0;
	fl->dot = 0;
	if (str[len] == '.')
	{
		fl->precision = 0;
		fl->dot = 1;
		len++;
	}
	if (ft_isdigit(str[len]) != 1)
		return ;
	ft_findlp1(str, fl, pos, len);
}

void		utf_parselenstr(t_conv *fl, int len, wchar_t *wstr)
{
	if (fl->width >= len && fl->width != 0)
		if (fl->precision > 0 && fl->precision < len &&\
		fl->width > fl->precision)
			fl->width -= fl->precision;
	if (fl->precision > 0 && fl->width >= fl->precision)
		fl->width -= ulen(wstr, fl);
	if (fl->dot == FALSE && len > fl->width)
		fl->width = 0;
	if (fl->precision > 0 && fl->precision >= len)
		fl->precision = 0;
}
