/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:00:26 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/24 13:12:55 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strnchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (s)
	{
		i = 0;
		str = (char *)s;
		while (str[i] != c)
		{
			if (str[i] == '\0')
				return (-1);
			i++;
		}
		return (i);
	}
	return (-1);
}
