/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:31:33 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/21 14:26:34 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_printf.h"

char		*ft_itoa_base(uintmax_t nb, int base, int capitilise)
{
	char	*res;
	int		len;
	char	*symb_lower;
	char	*symb_upper;

	len = ft_len_u(nb, base);
	symb_lower = "0123456789abcdef";
	symb_upper = "0123456789ABCDEF";
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (capitilise) ? symb_upper[nb % base] : symb_lower[nb % base];
		nb /= base;
	}
	return (res);
}
