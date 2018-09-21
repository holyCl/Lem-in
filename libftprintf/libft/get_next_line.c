/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:01:39 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 17:43:14 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list_fd	*true_fd(t_list **lst, const int fd)
{
	t_list		*curr;
	t_list_fd	*content;

	curr = *lst;
	while (curr)
	{
		if (((t_list_fd *)curr->content)->fd == fd)
			return ((t_list_fd *)curr->content);
		curr = curr->next;
	}
	if (!(content = (t_list_fd *)malloc(sizeof(t_list_fd))))
		return (NULL);
	content->text = ft_strnew(0);
	content->fd = fd;
	curr = ft_lstnew(content, sizeof(t_list_fd));
	curr->next = *lst;
	*lst = curr;
	free(content);
	content = NULL;
	return ((t_list_fd *)curr->content);
}

static	int			writing(t_list_fd *curr, char **line)
{
	char *end;
	char *tmp;

	if (!curr->text[0])
		return (0);
	if ((end = ft_strchr(curr->text, '\n')))
	{
		if (!(*line = ft_strsub(curr->text, 0, ft_strlen(curr->text)
								- ft_strlen(end))))
			return (-1);
		if (!(tmp = ft_strdup(++end)))
			return (-1);
		free(curr->text);
		curr->text = tmp;
		return (1);
	}
	else
	{
		*line = curr->text;
		if (!(curr->text = ft_strnew(0)))
			return (-1);
		return (1);
	}
}

static	int			reading(int bytes, t_list_fd *curr, char *buff)
{
	char *tmp;

	while (ft_strchr(curr->text, '\n') == NULL)
	{
		if ((bytes = read(curr->fd, buff, BUFF_SIZE)) < 1)
			break ;
		buff[bytes] = '\0';
		if (!(tmp = ft_strjoin(curr->text, buff)))
			return (-1);
		free(curr->text);
		curr->text = tmp;
	}
	if (ft_strlen(curr->text) == 0 && bytes == 0)
		return (0);
	if (bytes == -1)
		return (-1);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				bytes;
	t_list_fd		*curr;
	char			buff[BUFF_SIZE + 1];

	bytes = 0;
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	curr = true_fd(&lst, fd);
	bytes = reading(bytes, curr, buff);
	if (bytes < 1)
		return (bytes);
	return (writing(curr, line));
}
