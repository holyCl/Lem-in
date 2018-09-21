/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:51:25 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/03 17:26:45 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	int				i;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (src1[i] != '\0')
	{
		dst1[i] = src1[i];
		i++;
	}
	dst1[i] = '\0';
	return (dst);
}
