/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:30:48 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/04 18:44:58 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	temp = 0;
	i = -1;
	while (src[++i])
		;
	temp = i;
	i = -1;
	while (dst[++i] && i < size)
		;
	temp += (i < size) ? i : size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (temp);
}
