/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:33:33 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/02 16:33:38 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	size_t			i;

	i = -1;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dest;
	if (dst1 > src1)
	{
		while (n--)
			dst1[n] = src1[n];
	}
	else
		while (++i < n)
			dst1[i] = src1[i];
	return (dest);
}
