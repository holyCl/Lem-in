/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:29:21 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/04 16:32:11 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;
	size_t			len;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	len = ft_strlen(s1);
	while (str2[i] != '\0')
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (s1);
}
