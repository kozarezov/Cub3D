/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:18:35 by ceccentr          #+#    #+#             */
/*   Updated: 2020/07/22 15:56:00 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl				*ft_lstadd_front_gnl(t_gnl **head, t_gnl *new)
{
	if (head)
		new->next = *head;
	*head = new;
	return (*head);
}

t_gnl				*check_fd(t_gnl *head, int fd)
{
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_gnl				*new_list(int fd)
{
	t_gnl			*new_elem;

	new_elem = (t_gnl *)malloc(sizeof(t_gnl));
	if (fd < 0 || !(new_elem))
		return (NULL);
	new_elem->fd = fd;
	new_elem->content = ft_strdup("");
	new_elem->next = NULL;
	return (new_elem);
}

int					get_line(t_gnl **head, t_gnl *tmp, char **line)
{
	int				len;
	char			*rest;
	t_gnl			*head_tmp;

	head_tmp = *head;
	if (!ft_strchr(tmp->content, '\n'))
	{
		*line = ft_strdup(tmp->content);
		if (head_tmp != tmp)
		{
			while (head_tmp->next && head_tmp->next->fd != tmp->fd)
				head_tmp = head_tmp->next;
			head_tmp->next = tmp->next;
		}
		free(tmp->content);
		free(tmp);
		*head = (head_tmp == tmp) ? NULL : head_tmp;
		return (0);
	}
	len = (int)(ft_strchr(tmp->content, '\n') - tmp->content);
	*line = ft_substr(tmp->content, 0, len);
	rest = ft_strdup(tmp->content + len + 1);
	free(tmp->content);
	tmp->content = rest;
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	char			buf[100];
	int				count;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!head && !(head = new_list(fd)))
		return (-1);
	tmp = check_fd(head, fd);
	if (!(tmp) && !(tmp = ft_lstadd_front_gnl(&head, new_list(fd))))
		return (-1);
	while (!(ft_strchr(tmp->content, '\n')) &&
			(count = read(fd, buf, 100)) > 0)
	{
		buf[count] = '\0';
		tmp->content = ft_strjoin_gnl(tmp->content, buf, 1);
	}
	return (get_line(&head, tmp, line));
}
