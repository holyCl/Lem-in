/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:43:41 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/13 16:18:32 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_div(int nb)
{
	int div;
	int temp;

	div = 1;
	temp = nb / 10;
	while (temp)
	{
		div *= 10;
		temp /= 10;
	}
	return (div);
}

void		ft_putnbr_fd(int n, int fd)
{
	int			div;
	long int	bignb;

	bignb = n;
	div = ft_find_div(bignb);
	if (bignb < 0)
	{
		ft_putchar_fd('-', fd);
		bignb = -bignb;
	}
	if (div == 1)
	{
		ft_putchar_fd('0' + bignb, fd);
	}
	else
	{
		while (div)
		{
			ft_putchar_fd((bignb / div) + '0', fd);
			bignb -= (bignb / div) * div;
			div /= 10;
		}
	}
}
