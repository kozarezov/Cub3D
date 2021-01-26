/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:35:36 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/10 10:37:38 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (del != NULL && lst != NULL)
	{
		while (*lst != NULL)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = temp;
		}
	}
}
