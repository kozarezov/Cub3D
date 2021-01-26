/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_health_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:58:12 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/14 10:13:07 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void				blood(t_data *img, int v_offset, int win_w)
{
	int				i;
	int				j;
	unsigned int	color;
	int				h_offset;
	t_pic			*texture;

	i = 0;
	texture = ft_search_texture_id(img, 105);
	texture->addr = mlx_get_data_addr(texture->texture, \
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	h_offset = win_w - texture->img_width;
	while (i < texture->img_width)
	{
		j = 0;
		while (j < texture->img_height)
		{
			color = my_mlx_pixel_take(texture, i, j);
			if (((unsigned char)color != (unsigned char)0))
				my_mlx_pixel_put(img, i + h_offset, j + v_offset, color);
			j++;
		}
		i++;
	}
}

void				if_blood(t_data *img)
{
	if (img->hp < 60)
	{
		blood(img, img->config->win_h / 3, img->config->win_w);
		if (img->hp < 30)
			blood(img, img->config->win_h / 2, img->config->win_w / 2);
	}
}

void				bar(t_data *img, int h_offset)
{
	int				start_x;
	int				start_y;
	int				finish_x;
	int				finish_y;

	start_x = h_offset + 47;
	start_y = 17;
	finish_x = start_x + 188 * img->hp / 100;
	finish_y = start_y + 31;
	while (start_x < finish_x)
	{
		start_y = 19;
		while (start_y < finish_y)
		{
			my_mlx_pixel_put(img, start_x, start_y, ft_puck_rgb(184, 15, 10));
			start_y++;
		}
		start_x++;
	}
}

void				ft_health(t_data *img)
{
	int				i;
	int				j;
	unsigned int	color;
	int				h_offset;
	t_pic			*texture;

	i = 0;
	texture = ft_search_texture_id(img, 104);
	texture->addr = mlx_get_data_addr(texture->texture, \
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	h_offset = img->config->win_w - texture->img_width;
	bar(img, h_offset);
	if_blood(img);
	while (i < texture->img_width)
	{
		j = 0;
		while (j < texture->img_height)
		{
			color = my_mlx_pixel_take(texture, i, j);
			if (((unsigned char)color != (unsigned char)0))
				my_mlx_pixel_put(img, i + h_offset, j, color);
			j++;
		}
		i++;
	}
}
