/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:47:57 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/17 15:33:24 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void			check_ants_count(t_lm *st)
{
	int			i;

	i = -1;
	if (!st->line[++i])
		error(101, st);
	while (st->line[++i])
		if (!ft_isdigit(st->line[i]))
			error(101, st);
}

t_room			*search_right_room(t_room *st, char *room)
{
	while (st)
	{
		if (!ft_strcmp(st->name, room))
			return (st);
		st = st->next;
	}
	return (NULL);
}

void			printing_way(t_room *room, int *cur_ant, int *count)
{
	room->root->ants--;
	room->ants++;
	(*cur_ant)++;
	(*count == 0) ? (*count)++ : ft_printf(" ");
	write(1, "\033[1;31m", 7);
	ft_printf("L%d-%s", *cur_ant, room->name);
	write(1, "\033[0m", 4);
}

void			output_ants(t_lm *st)
{
	t_room		*room;
	t_room		*finish;
	int			cur_ant;
	int			count;

	room = search_right_room(st->room, st->start);
	finish = search_right_room(st->room, st->end);
	room->ants = st->ants;
	while (finish->ants < st->ants)
	{
		room = finish;
		cur_ant = finish->ants;
		count = 0;
		while (ft_strcmp(room->name, st->start))
		{
			if (!room->root)
				error(604, st);
			if (room->root->ants != 0)
				printing_way(room, &cur_ant, &count);
			room = room->root;
		}
		ft_printf("\n");
	}
}
