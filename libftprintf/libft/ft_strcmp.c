/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:00:23 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/06 15:17:43 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while ((str1[i] != '\0' || str2[i] != '\0') && (str2[i] && str1[i]))
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	return (0);
}
