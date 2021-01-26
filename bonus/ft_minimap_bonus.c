/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:09:17 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/14 10:13:12 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		player_on_map(t_data *img, float x, float y)
{
	float	i;
	float	j;
	int		cx;
	int		cy;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			cx = x * img->rect_w + i;
			cy = y * img->rect_h + j;
			j++;
			my_mlx_pixel_put(img, cx, cy, ft_puck_rgb(184, 15, 10));
		}
		i++;
	}
}

void		sprite_on_map(t_data *img)
{
	t_pic	*sprite;
	int		num_sprite;

	num_sprite = 0;
	while (1)
	{
		if (!(sprite = ft_search_texture_id(img, num_sprite)))
			break ;
		player_on_map(img, sprite->sprite_x, sprite->sprite_y);
		num_sprite++;
	}
}

void		scale_map(t_data *img, int x, int y, int color)
{
	size_t	i;
	size_t	j;
	int		cx;
	int		cy;

	i = 0;
	while (i < img->rect_w)
	{
		j = 0;
		while (j < img->rect_h)
		{
			cx = x + i;
			cy = y + j;
			j++;
			if (cx >= img->config->win_w || cy >= img->config->win_h)
			{
				j++;
				continue;
			}
			my_mlx_pixel_put(img, cx, cy, color);
		}
		i++;
	}
}

void		ft_minimap(t_data *img)
{
	int		rect_x;
	int		rect_y;
	int		i;
	int		j;

	j = 0;
	while (j < img->config->map_h)
	{
		i = 0;
		while (i < img->config->map_w)
		{
			rect_x = i * img->rect_w;
			rect_y = j * img->rect_h;
			if (img->map[i + j * img->config->map_w] != '1')
				scale_map(img, rect_x, rect_y, ft_puck_rgb(255, 255, 255));
			else
				scale_map(img, rect_x, rect_y, ft_puck_rgb(0, 0, 0));
			i++;
		}
		j++;
	}
	sprite_on_map(img);
	player_on_map(img, img->player_x, img->player_y);
}
