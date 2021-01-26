/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_texture_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 23:05:14 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/10 23:05:38 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pic		*ft_search_texture_id(t_data *img, int text_id)
{
	t_pic	*temp;

	temp = img->pic;
	while (temp != NULL)
	{
		if (temp->text_id == text_id)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
