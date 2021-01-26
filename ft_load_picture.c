/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_picture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:08:11 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/10 18:08:34 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int			ft_load_picture(t_data *img, int x, int y, int textid)
{
	unsigned int		color;
	t_pic				*texture;

	texture = ft_search_texture_id(img, textid);
	texture->addr = mlx_get_data_addr(texture->texture, \
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	color = my_mlx_pixel_take(texture, x, y);
	return (color);
}
