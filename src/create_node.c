/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:43:30 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/16 15:47:32 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void			add_to_path(t_lm **st, t_room *room)
{
	t_way		*path;
	t_way		*node;

	path = (*st)->way;
	while (path)
	{
		if (path->room == room)
			return ;
		path = path->next;
	}
	node = malloc(sizeof(t_way));
	node->room = room;
	node->next = NULL;
	if (!(*st)->way)
		(*st)->way = node;
	else
	{
		path = (*st)->way;
		while (path->next)
			path = path->next;
		path->next = node;
	}
	room->visit = 1;
}

t_room			*get_room1(t_way **room)
{
	t_room		*temp;
	t_way		*way;

	way = *room;
	if (way)
	{
		temp = way->room;
		*room = (*room)->next;
		ft_memdel((void **)&way);
		return (temp);
	}
	return (NULL);
}

void			connect(t_lm *st)
{
	t_link		*temp;
	t_room		*cur;
	t_room		*dst;

	temp = st->link;
	while (temp)
	{
		cur = search_right_room(st->room, temp->cur);
		dst = search_right_room(st->room, temp->dest);
		if (cur && dst)
		{
			connect_link(cur, dst);
			connect_link(dst, cur);
		}
		temp = temp->next;
	}
	ft_printf("\n");
}

void			findway(t_lm *st)
{
	t_room		*room;
	t_way		*edge;

	room = search_right_room(st->room, st->start);
	add_to_path(&st, room);
	while (st->way)
	{
		room = get_room1(&st->way);
		room->visit = 1;
		edge = room->way;
		while (edge)
		{
			if (!ft_strcmp(room->name, st->end))
				break ;
			if (edge->room->visit == 0)
			{
				add_to_path(&st, edge->room);
				edge->room->root = room;
			}
			edge = edge->next;
		}
	}
}
