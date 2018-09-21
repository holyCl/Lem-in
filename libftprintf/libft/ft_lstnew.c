/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:28:36 by ivoloshi          #+#    #+#             */
/*   Updated: 2017/11/17 19:08:38 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;
	void	*cpcontent;
	size_t	*cpcont_size;

	if ((nlist = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		cpcontent = ft_memalloc(content_size);
		cpcont_size = &content_size;
		ft_memcpy(cpcontent, content, *cpcont_size);
		nlist->content = cpcontent;
		nlist->content_size = *cpcont_size;
	}
	else
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	nlist->next = NULL;
	return (nlist);
}
