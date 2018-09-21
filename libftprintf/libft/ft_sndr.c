/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchandreplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:25:51 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 16:15:36 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_sndr(char *str, char elemf, char elemsrc)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == elemf)
			str[i] = elemsrc;
		i++;
	}
	return (*str);
}
