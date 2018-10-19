/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:26:08 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/16 18:57:00 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void			write_comment(t_lm *st, int fd)
{
	if (st->line[0] == '#' && st->line[1] != '#')
	{
		ft_putendl(st->line);
		free(st->line);
		get_next_line(fd, &st->line);
	}
}

void			add_ants(t_lm *st, int *i)
{
	check_ants_count(st);
	st->ants = ft_atoi(st->line);
	if (st->ants <= 0)
		error(101, st);
	ft_printf("%d\n", st->ants = ft_atoi(st->line));
	(*i)++;
}

void			prepare_room(t_lm *st)
{
	if (st->line[0] == '\0')
	{
		st->flag = 1;
		return ;
	}
	if (!check_link(st->line))
	{
		add_new_room(st);
		ft_putendl(st->line);
	}
	else
		add_new_link(st);
}

int				len_mas(char **tmp)
{
	int			i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int				check_link(char *str)
{
	int			count;
	int			spaces;

	spaces = 0;
	count = 0;
	while (*str)
	{
		if (*str == '-')
			count++;
		if (*str == ' ')
			spaces++;
		str++;
	}
	if (spaces == 2 && count == 1)
		return (0);
	if (count == 1)
		return (1);
	return (0);
}
