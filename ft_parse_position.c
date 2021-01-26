/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:42:37 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/12 10:51:54 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_texture(t_data *img, t_conf *config)
{
	int		fd;

	if ((fd = open(config->north, O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open(config->south, O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open(config->east, O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open(config->west, O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open(config->sprite, O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open("textures/health.xpm", O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open("textures/blood.xpm", O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open("textures/pistolet.xpm", O_RDONLY)) < 0)
		return (ft_exit(2, img));
	if ((fd = open("textures/pistolet0.xpm", O_RDONLY)) < 0)
		return (ft_exit(2, img));
	return (0);
}

int			parse_texture(t_data *img, t_conf *config)
{
	if (!(ft_new_elem(img, config->north, 0, 100)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, config->south, 0, 101)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, config->east, 0, 102)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, config->west, 0, 103)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, "textures/health.xpm", 0, 104)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, "textures/blood.xpm", 0, 105)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, "textures/pistolet.xpm", 0, 106)))
		return (ft_exit(5, img));
	if (!(ft_new_elem(img, "textures/pistolet0.xpm", 0, 107)))
		return (ft_exit(5, img));
	return (1);
}

void		player_position(t_data *img, t_conf *config, int i, int j)
{
	img->player_x = (float)i + 0.5;
	img->player_y = (float)j + 0.5;
	if (config->map_temp[i + j * img->config->map_w] == 'S')
		img->player_a = M_PI / 2;
	if (config->map_temp[i + j * img->config->map_w] == 'N')
		img->player_a = 3 * M_PI / 2;
	if (config->map_temp[i + j * img->config->map_w] == 'E')
		img->player_a = 2 * M_PI;
	if (config->map_temp[i + j * img->config->map_w] == 'W')
		img->player_a = M_PI;
	config->map_temp[i + j * img->config->map_w] = '0';
}

int			player_sprite(t_data *img, t_conf *config, char *tex_id, int num_p)
{
	int		i;
	int		j;
	int		num_s;

	i = -1;
	num_s = 0;
	while (++i < config->map_w)
	{
		j = -1;
		while (++j < config->map_h)
		{
			if (ft_isalpha(config->map_temp[i + j * img->config->map_w]))
			{
				player_position(img, config, i, j);
				num_p++;
			}
			if (config->map_temp[i + j * img->config->map_w] == '2')
			{
				img->sprite_x = i;
				if (!(ft_new_elem(img, tex_id, j, num_s++)))
					return (ft_exit(5, img));
			}
		}
	}
	return (num_p);
}

int			ft_parse_pos(t_data *img, t_conf *config, char *texture_id)
{
	int		num_player;

	check_texture(img, config);
	num_player = 0;
	num_player = player_sprite(img, config, texture_id, num_player);
	if (num_player != 1)
		return (ft_exit(3, img));
	img->sprite_x = 0;
	img->sprite_y = 0;
	parse_texture(img, config);
	return (1);
}
