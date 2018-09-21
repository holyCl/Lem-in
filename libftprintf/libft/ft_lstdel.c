/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:24:52 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 19:09:25 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*node;

	node = *alst;
	while (node)
	{
		temp = node->next;
		del(node, node->content_size);
		node = temp;
	}
	*alst = NULL;
}
