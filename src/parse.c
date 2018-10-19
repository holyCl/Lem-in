/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:58:09 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/17 15:59:13 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <fcntl.h>

void			check_links(t_lm *st)
{
	int			flag1;
	int			flag2;
	t_room		*temp;
	t_link		*link;

	link = st->link;
	while (link)
	{
		temp = st->room;
		flag1 = 0;
		flag2 = 0;
		while (temp && (!flag1 || !flag2))
		{
			if (!ft_strcmp(link->cur, temp->name))
				flag1 = 1;
			if (!ft_strcmp(link->dest, temp->name))
				flag2 = 1;
			temp = temp->next;
		}
		if (!flag1 || !flag2)
			error(401, st);
		link = link->next;
	}
}

void			create_start(t_lm *st, int fd)
{
	if (!st->start)
	{
		ft_putendl(st->line);
		free(st->line);
		get_next_line(fd, &st->line);
		write_comment(st, fd);
		st->cordstart = ft_strsplit(st->line, ' ');
		if (len_mas(st->cordstart) != 3)
			error(501, st);
		st->start = st->cordstart[0];
		add_new_room(st);
		if (st->flag)
			return ;
	}
	else
		error(301, st);
}

void			create_end(t_lm *st, int fd)
{
	if (!st->end)
	{
		ft_putendl(st->line);
		free(st->line);
		get_next_line(fd, &st->line);
		write_comment(st, fd);
		st->cordend = ft_strsplit(st->line, ' ');
		if (len_mas(st->cordend) != 3)
			error(501, st);
		st->end = st->cordend[0];
		if (!search_right_room(st->room, *st->cordend))
		{
			add_new_room(st);
			if (st->flag)
				return ;
		}
		else
			error(201, st);
	}
	else
		error(300, st);
}

void			check_coment(t_lm *st, int fd, int *i)
{
	if (ft_strcmp(st->line, "##start") == 0)
	{
		create_start(st, fd);
		if (st->flag)
			return ;
	}
	else if (ft_strcmp(st->line, "##end") == 0)
	{
		create_end(st, fd);
		if (st->flag)
			return ;
	}
	if (st->line[1] != '#')
		ft_putendl(st->line);
	(*i)++;
}

void			parse(t_lm *st)
{
	int			i;
	int			fd;

	fd = 0;
	i = 0;
	while (get_next_line(fd, &st->line) > 0)
	{
		if (parse1(st))
			continue ;
		if (i == 0)
			add_ants(st, &i);
		else if (st->line[0] != '#')
		{
			prepare_room(st);
			if (st->flag)
				return ;
		}
		else
		{
			check_coment(st, fd, &i);
			if (st->flag)
				return ;
		}
		free(st->line);
	}
}
