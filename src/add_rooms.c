/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:49:56 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/17 15:41:02 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void			clear(t_lm *st)
{
	int			i;

	i = 0;
	while (st->tmp && st->tmp[i])
	{
		free(st->tmp[i]);
		i++;
	}
	if (st->tmp)
		free(st->tmp);
}

int				check_digits(t_lm *st)
{
	int			i;
	size_t		len;

	i = 0;
	len = ft_strlen(st->tmp[1]);
	while (len--)
	{
		if (st->tmp[1][0] == '-')
			i++;
		else if (!ft_isdigit(st->tmp[1][i]))
			return (0);
		i++;
	}
	i = 0;
	len = ft_strlen(st->tmp[2]);
	while (len--)
	{
		if (st->tmp[2][0] == '-')
			i++;
		else if (!ft_isdigit(st->tmp[2][i]))
			return (0);
		i++;
	}
	return (1);
}

int				add_new_room(t_lm *st)
{
	t_room		*temp;

	st->tmp = ft_strsplit(st->line, ' ');
	if (st->tmp[0] && !st->tmp[1])
	{
		st->flag = 1;
		return (0);
	}
	if (!st->tmp[1] || !st->tmp[2])
		error(501, st);
	if (!check_digits(st))
		error(501, st);
	if (!(temp = (t_room *)malloc(sizeof(t_room))))
		exit(1);
	temp->name = ft_strdup(st->tmp[0]);
	valid_init_room(temp, st);
	st->room = temp;
	st->count_rooms++;
	clear(st);
	check_rooms(st);
	return (1);
}

void			check_rooms(t_lm *st)
{
	t_room		*cur;
	t_room		*dest;

	cur = st->room;
	while (cur)
	{
		dest = cur->next;
		while (dest)
		{
			if (!ft_strcmp(cur->name, dest->name))
				error(201, st);
			if (cur->x == dest->x && cur->y == dest->y)
				error(202, st);
			dest = dest->next;
		}
		cur = cur->next;
	}
	check_links(st);
}
