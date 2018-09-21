/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:56:51 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 20:22:27 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*temp;
	int		i;

	count = 0;
	i = 0;
	while (s1[i++] != '\0')
		count++;
	i = -1;
	if ((temp = (char *)malloc(sizeof(char) * count + 1)) == NULL)
		return (NULL);
	while (++i < count)
		*(temp + i) = *(s1 + i);
	*(temp + i) = '\0';
	return (temp);
}
