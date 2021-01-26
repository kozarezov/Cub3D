/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:54:55 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/07 17:43:50 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new_element = ft_lstnew(f(lst->content))))
		return (NULL);
	new_list = new_element;
	lst = lst->next;
	while (lst)
	{
		if (!(new_element = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
