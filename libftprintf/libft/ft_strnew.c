/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:01:03 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/07 16:58:45 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	if ((newstr = ft_memalloc(++size)))
	{
		i = 0;
		while (i < size)
		{
			newstr[i] = '\0';
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
