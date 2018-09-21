/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:13:55 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 19:53:16 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	if (len == 0)
		return (b);
	tmp = (unsigned char *)b;
	while (len--)
	{
		*tmp = (unsigned char)c;
		if (len)
			tmp++;
	}
	return (b);
}
