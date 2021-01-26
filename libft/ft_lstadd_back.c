/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:37:28 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/10 10:37:41 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (*lst != NULL && lst != NULL)
	{
		last_element = ft_lstlast(*lst);
		last_element->next = new;
	}
	else
		*lst = new;
}
