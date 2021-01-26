/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hand_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:45:30 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/14 10:14:12 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int		ft_load_hand(t_pic *hand, int x, int y)
{
	int				color;

	hand->addr = mlx_get_data_addr(hand->texture, &hand->bits_per_pixel, \
			&hand->line_length, &hand->endian);
	color = my_mlx_pixel_take(hand, x, y);
	return (color);
}

void				put_text(t_data *img, t_pic *hand, int hand_s, int h)
{
	int				i;
	int				j;
	unsigned int	color;
	int				w;

	i = 0;
	w = img->config->win_h - hand_s;
	while (i < hand_s)
	{
		j = -1;
		if (h + i > 0 && h + i < img->config->win_w)
		{
			while (++j < hand_s)
			{
				if (w + j > 0 && w + j < img->config->win_h)
				{
					color = ft_load_hand(hand, i * TEXT_SIZE / \
							hand_s, j * TEXT_SIZE / hand_s);
					if (((unsigned char)color != (unsigned char)0))
						my_mlx_pixel_put(img, h + i, w + j, color);
				}
			}
		}
		i++;
	}
}

void				ft_hand(t_data *img)
{
	int				hand_size;
	int				h_offset;
	int				v_offset;
	t_pic			*texture;

	texture = ft_search_texture_id(img, img->hand);
	hand_size = img->config->win_h / 4;
	h_offset = (img->config->win_w) / 2 - texture->img_width;
	v_offset = img->config->win_h - hand_size;
	put_text(img, texture, hand_size, h_offset);
}
