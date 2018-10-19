/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <ivoloshi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:42:27 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/10/17 15:32:41 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static void		error1(int numb, t_lm *st)
{
	if (numb == 303)
		ft_printf("ERROR:end does not exist\n");
	if (numb == 401)
		ft_printf("ERROR:Connecting to non-existing room\n");
	if (numb == 501)
		ft_printf("ERROR:Uncorrected room\n");
	if (numb == 502)
		ft_printf("ERROR:Uncorrected link\n");
	if (numb == 603)
		ft_printf("ERROR:Syntax Error\n");
	if (numb == 604)
		ft_printf("ERROR:Broken way\n");
	if (numb == 701)
		ft_printf("ERROR:Name begin with 'L'\n");
	free(st->line);
	exit(1);
}

void			error(int numb, t_lm *st)
{
	if (numb != 302)
		if (numb != 604)
			ft_putendl(st->line);
	if (numb == 101)
		ft_printf("ERROR:Incorrect number of ants\n");
	if (numb == 201)
		ft_printf("ERROR:rooms has same names\n");
	if (numb == 202)
		ft_printf("ERROR:rooms has same cords\n");
	if (numb == 301)
		ft_printf("ERROR:start allready exist\n");
	if (numb == 300)
		ft_printf("ERROR:end allready exist\n");
	if (numb == 302)
		ft_printf("ERROR:start does not exist\n");
	error1(numb, st);
}
