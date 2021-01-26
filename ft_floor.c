/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:41:13 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/10 17:42:10 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_floor(t_data *img, int i, float t, float ray)
{
	int		x;
	int		y;
	int		color;

	x = i;
	color = ft_puck_rgb(img->config->floor[0], img->config->floor[1], \
			img->config->floor[2]);
	y = img->config->win_h / 2 + img->config->win_h / 2 / \
			(t * cos(ray - img->player_a));
	while (y < img->config->win_h)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
	return (0);
}
