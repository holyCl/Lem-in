/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:43:41 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/13 16:17:33 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_find_div(int nb)
{
	int	div;
	int	temp;

	div = 1;
	temp = nb / 10;
	while (temp)
	{
		div *= 10;
		temp /= 10;
	}
	return (div);
}

void		ft_putnbr(int nb)
{
	int			div;
	long int	bignb;

	bignb = nb;
	div = ft_find_div(bignb);
	if (bignb < 0)
	{
		ft_putchar('-');
		bignb = -bignb;
	}
	if (div == 1)
	{
		ft_putchar('0' + bignb);
	}
	else
	{
		while (div)
		{
			ft_putchar((bignb / div) + '0');
			bignb -= (bignb / div) * div;
			div /= 10;
		}
	}
}
