/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:23:30 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:10:10 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_parseconv(t_conv *fl, va_list *arg_ptr)
{
	int		ret;

	ret = 0;
	if (fl->conv == 'd' || fl->conv == 'i')
		ret = ft_numbers(fl, arg_ptr);
	else if (fl->conv == 's')
		ret = ft_str(fl, arg_ptr);
	else if (fl->conv == 'c' || fl->conv == '%')
		ret = ft_chars(fl, arg_ptr);
	else if (fl->conv == 'o')
		ret = fl_unsconv(fl, arg_ptr, 8);
	else if (fl->conv == 'u')
		ret = fl_unsconv(fl, arg_ptr, 10);
	else if (fl->conv == 'x' || fl->conv == 'X')
		ret = fl_unsconv(fl, arg_ptr, 16);
	else if (fl->conv == 'p')
		ret = ft_point(fl, arg_ptr, 16);
	return (ret);
}

char		ft_tolow(char a)
{
	char	r;

	if (a >= 'A' && a <= 'Z')
	{
		r = a + 32;
		return (r);
	}
	return (a);
}

int			ft_conv(char str, t_conv *fl, va_list *arg_ptr)
{
	int		ret;

	ret = 0;
	if (str == 'C' || str == 'U' || str == 'S' || \
		str == 'D' || str == 'O')
	{
		fl->lenght.len_l = 1;
		fl->conv = ft_tolow(str);
	}
	else
		fl->conv = str;
	ret = ft_parseconv(fl, arg_ptr);
	return (ret);
}

t_conv		ft_checkfalgs(char str, t_conv *fl)
{
	str == '#' ? fl->flags.hash += TRUE : FALSE;
	str == '-' ? fl->flags.minus += TRUE : FALSE;
	str == '+' ? fl->flags.plus += TRUE : FALSE;
	str == ' ' ? fl->flags.blank += TRUE : FALSE;
	str == '0' ? fl->flags.zeros += TRUE : FALSE;
	str == 'h' ? fl->lenght.len_h += TRUE : FALSE;
	str == 'l' ? fl->lenght.len_l += TRUE : FALSE;
	str == 'j' ? fl->lenght.len_j += TRUE : FALSE;
	str == 'z' ? fl->lenght.len_z += TRUE : FALSE;
	return (*fl);
}
