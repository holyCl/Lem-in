/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:40:51 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/05/23 13:08:27 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		flags(char **str, t_conv *new, size_t i)
{
	if (*(*str + i - 1) == '+' && *(*str + i) == '+')
		new->flags.plus = TRUE;
	else
		*new = ft_checkfalgs(*(*str + i), new);
}

int			unvalid(char **str, size_t *i, t_conv *new, int *step)
{
	if ((ft_strchr(FLAGS, *(*str + *i)) == NULL) &&\
			(ft_strchr(DIGITS, *(*str + *i)) == NULL))
	{
		another_symb(*(*str + *i), new, step);
		*i += 1;
		return (1);
	}
	return (0);
}

size_t		ft_read2(char **str, va_list *arg_ptr, int *step, size_t i)
{
	t_conv	new;

	ft_bzero(&new, sizeof(t_conv));
	while (*(*str + i))
	{
		if (ft_strchr(FLAGS, *(*str + i)))
			flags(str, &new, i);
		if (strchr(DIGITS, *(*str + i)) && *(*str + i) != '0')
			ft_findlp(*str + i, &new, &i);
		if (strchr(CONV, *(*str + i)))
		{
			*step += ft_conv(*(*str + i++), &new, arg_ptr);
			ft_bzero(&new, sizeof(t_conv));
			break ;
		}
		if (isascii(*(*str + i)))
			if (unvalid(str, &i, &new, step) == 1)
				break ;
		i++;
	}
	return (i);
}

size_t		ft_reading(char **str, va_list *arg_ptr, int *step)
{
	size_t	pos;

	pos = 0;
	if (*(*str += 1) == '%')
	{
		pf_write("%", 1, 1);
		*step += 1;
		*str += 1;
		return (0);
	}
	pos = ft_read2(str, arg_ptr, step, 0);
	return (pos);
}
