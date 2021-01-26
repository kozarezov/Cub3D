/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:52:57 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/14 11:21:01 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		load_s(t_pic *sprite, int x, int y)
{
	int				color;

	sprite->addr = mlx_get_data_addr(sprite->texture, \
			&sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
	color = my_mlx_pixel_take(sprite, x, y);
	return (color);
}

float				distance(t_data *img, t_pic *spr)
{
	float			dist;

	dist = sqrt(pow(img->player_x - spr->sprite_x, 2) + \
			pow(img->player_y - spr->sprite_y, 2));
	return (dist);
}

void				put_tex(t_data *img, t_pic *spr, int spr_size, int h)
{
	int				i;
	int				j;
	unsigned int	color;
	int				v;

	i = -1;
	v = img->config->win_h / 2 - spr_size / 2;
	while (++i < spr_size)
	{
		j = -1;
		if (h + i > 0 && h + i < img->config->win_w && \
				img->t[h + i] + 1.0 > distance(img, spr))
		{
			while (++j < spr_size)
			{
				if (v + j > 0 && v + j < img->config->win_h)
				{
					color = load_s(spr, i * TEXT_SIZE / \
							spr_size, j * TEXT_SIZE / spr_size);
					if (((unsigned char)color != (unsigned char)0))
						my_mlx_pixel_put(img, h + i, v + j, color);
				}
			}
		}
	}
}

void				draw_sprite(t_data *img, t_pic *sprite)
{
	float			dir;
	float			dist;
	int				spr_size;
	int				h_offset;
	int				v_offset;

	dir = atan2(sprite->sprite_y - img->player_y, \
			sprite->sprite_x - img->player_x);
	while (dir - img->player_a > M_PI)
		dir -= 2 * M_PI;
	while (dir - img->player_a < -M_PI)
		dir += 2 * M_PI;
	dist = distance(img, sprite);
	if (dist <= 0.1)
		img->hp -= 10;
	spr_size = img->config->win_h / dist;
	h_offset = (dir - img->player_a) * (img->config->win_w) / \
			(img->fov) + (img->config->win_w) / 2 - spr_size / 2;
	v_offset = img->config->win_h / 2 - spr_size / 2;
	put_tex(img, sprite, spr_size, h_offset);
}

int					ft_sprite(t_data *img)
{
	t_pic			*sprite;
	int				num_sprite;
	float			*dist;
	int				*sort;

	num_sprite = 0;
	while (1)
	{
		if (!(sprite = ft_search_texture_id(img, num_sprite)))
			break ;
		num_sprite++;
	}
	if (!(dist = (float*)malloc(sizeof(float) * (num_sprite + 1))))
		return (ft_exit(5, img));
	if (!(sort = (int*)malloc(sizeof(int) * (num_sprite + 1))))
		return (ft_exit(5, img));
	num_sprite = ft_sort(img, dist, sort);
	while (num_sprite-- > 0)
	{
		sprite = ft_search_texture_id(img, sort[num_sprite]);
		draw_sprite(img, sprite);
	}
	free(dist);
	free(sort);
	return (0);
}
