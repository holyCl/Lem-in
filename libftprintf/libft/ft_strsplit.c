/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:29:08 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/13 19:50:49 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	countw(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static	int	lenw(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		countword;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	countword = countw((const char *)s, c);
	if ((t = (char **)malloc(sizeof(*t) * (countw((const char *)s, c) + 1)))
		== NULL)
		return (NULL);
	while (countword--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_strsub((const char *)s, 0, lenw((const char *)s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + lenw(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
