/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:46:00 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/13 18:05:35 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)dst;
	while (n > i)
	{
		*str = *(char *)src;
		str++;
		src++;
		i++;
	}
	return (dst);
}
