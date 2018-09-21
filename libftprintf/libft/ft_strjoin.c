/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:36:05 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 18:47:59 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	tlength;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	tlength = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (tlength + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < tlength)
	{
		if (i >= ft_strlen(s1))
			str[i] = s2[j++];
		else
			str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
