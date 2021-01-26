/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:13:13 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/10 15:15:36 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_ceilling(t_data *img, int i, float t, float ray)
{
	int		x;
	int		y;
	int		color;

	x = i;
	color = ft_puck_rgb(img->config->ceilling[0], \
			img->config->ceilling[1], img->config->ceilling[2]);
	y = img->config->win_h / 2 - img->config->win_h / 2 / \
			(t * cos(ray - img->player_a));
	while (y > 0)
	{
		my_mlx_pixel_put(img, x, y, color);
		y--;
	}
	return (0);
}
