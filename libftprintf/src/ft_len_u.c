/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:30:17 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 16:09:37 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_len_u(uintmax_t nb, int base)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int		ulen(wchar_t *str, t_conv *fl)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		i++;
		len += ft_ucharlen(str[i]);
		if (fl->precision < len)
			return (len - ft_ucharlen(str[i]));
	}
	return (len);
}
