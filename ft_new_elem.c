/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:12:02 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/12 10:39:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pic		*ft_new_elem(t_data *img, char *text_id, int y, int sprid)
{
	t_pic	*new;

	if (!(new = (t_pic*)malloc(sizeof(t_pic))))
		return (NULL);
	new->text_id = sprid;
	new->texture = mlx_xpm_file_to_image(img->mlx, text_id, \
			&new->img_width, &new->img_height);
	new->sprite_x = (float)img->sprite_x + 0.5;
	new->sprite_y = (float)y + 0.5;
	new->next = img->pic;
	img->pic = new;
	return (new);
}
