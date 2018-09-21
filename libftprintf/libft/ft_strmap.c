/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:03:36 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/07 20:16:57 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
