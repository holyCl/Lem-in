/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:36:11 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/08 15:53:23 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n > 0)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
			{
				i++;
				n--;
				if (n == 0)
					return (1);
			}
			else
				return (0);
		}
	}
	return (1);
}
