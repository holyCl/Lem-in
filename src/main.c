/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:41:10 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/17 16:12:59 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			parse1(t_lm *st)
{
	if (st->line[0] == '#' && st->line[1] != '#')
	{
		ft_putendl(st->line);
		free(st->line);
		return (1);
	}
	return (0);
}

void		valid_init_room(t_room *temp, t_lm *st)
{
	if (st->tmp[0][0] == 'L')
		error(701, st);
	if (st->tmp[3])
		error(501, st);
	temp->x = ft_atoi(st->tmp[1]);
	temp->y = ft_atoi(st->tmp[2]);
	temp->next = st->room;
	temp->way = st->way;
	temp->visit = 0;
	temp->ants = 0;
}

void		initialise(t_lm *st)
{
	st->start = NULL;
	st->end = NULL;
	st->line = NULL;
	st->tmp = NULL;
	st->cordend = NULL;
	st->cordend = NULL;
	st->count_rooms = 0;
	st->link = NULL;
	st->room = NULL;
	st->way = NULL;
	st->flag = 0;
}

int			main(void)
{
	t_lm	st;

	initialise(&st);
	parse(&st);
	valid(&st);
	connect(&st);
	findway(&st);
	output_ants(&st);
	return (0);
}
