/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:40:02 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/13 18:10:09 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n > 0)
	{
		*dst1 = *src1;
		if (*src1 == (unsigned char)c)
			return ((void *)(dst1 + 1));
		src1++;
		dst1++;
		n--;
	}
	return (NULL);
}
