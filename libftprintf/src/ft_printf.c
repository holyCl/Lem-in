/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:28:46 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:13:41 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list	arg_ptr;
	int		step;

	step = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += ft_reading(&format, &arg_ptr, &step);
			if (!(*format))
				break ;
		}
		else if (*format)
		{
			ft_putchar(*format);
			step++;
			format++;
		}
	}
	va_end(arg_ptr);
	return (step);
}
