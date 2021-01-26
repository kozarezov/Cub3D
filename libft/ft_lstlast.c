/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:42:03 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/07 13:08:55 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list *temp;

	if (lst != NULL)
	{
		temp = lst;
		while (temp->next != NULL)
			temp = temp->next;
		return (temp);
	}
	else
		return (NULL);
}
