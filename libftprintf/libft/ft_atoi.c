/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:24:50 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/10 18:43:27 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int						ft_atoi(const char *str)
{
	unsigned long int	n;
	int					sign;

	n = 0;
	sign = 1;
	while (whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		if (n >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (n > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(n * sign));
}
