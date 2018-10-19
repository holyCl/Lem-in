/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:34:31 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/16 15:39:22 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		valid_links(t_lm *st)
{
	if (ft_strstr(st->line, " "))
		error(502, st);
	if (!st->start)
		error(302, st);
	if (!st->end)
		error(303, st);
}

int			add_new_link(t_lm *st)
{
	t_link	*lk;
	char	**tmp;

	valid_links(st);
	if (st->line[0] != '#')
	{
		tmp = ft_strsplit(st->line, '-');
		lk = st->link;
		while (lk)
			lk = lk->next;
		lk = (t_link*)malloc(sizeof(t_link));
		if (!tmp[0] || !tmp[1])
			error(502, st);
		lk->cur = tmp[0];
		lk->dest = tmp[1];
		lk->next = st->link;
		st->link = lk;
	}
	ft_memdel((void **)&tmp);
	check_links(st);
	ft_putendl(st->line);
	return (1);
}

void		connect_link(t_room *cur, t_room *dst)
{
	t_way	*way;

	way = cur->way;
	while (way)
	{
		if (way->room == dst)
			return ;
		way = way->next;
	}
	way = malloc(sizeof(t_way *));
	way->room = dst;
	way->next = cur->way;
	cur->way = way;
}
