/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:16:46 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/10 15:18:05 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			wall_ray(t_data *img, float ray)
{
	float	t;
	float	ray_x;
	float	ray_y;

	t = 0;
	while (t < 0.4)
	{
		ray_x = img->player_x + t * cos(ray);
		ray_y = img->player_y + t * sin(ray);
		if (img->map[(int)(ray_x) + (int)(ray_y) * img->config->map_w] == '1')
			return (10);
		t += .01;
	}
	return (0);
}

int			ft_check_wall(t_data *img)
{
	int		i;
	float	ray;

	i = 0;
	while (i < 360)
	{
		ray = img->player_a - M_PI / 360 + img->fov * i;
		if (wall_ray(img, ray) == 10)
			return (10);
		i++;
	}
	return (0);
}
