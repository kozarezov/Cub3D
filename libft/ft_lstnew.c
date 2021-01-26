/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 09:12:36 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/07 17:02:23 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
