/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:55:37 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/14 10:37:09 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float		ft_raycasting(t_data *img, float ray, int i)
{
	float	ray_x;
	float	ray_y;
	float	t;

	t = 0;
	while (t < img->config->map_h + 1)
	{
		ray_x = img->player_x + t * cos(ray);
		ray_y = img->player_y + t * sin(ray);
		if (img->map[(int)(ray_x) + (int)(ray_y) * img->config->map_w] == '1')
		{
			img->column_h = img->config->win_h / (t * cos(ray - img->player_a));
			ft_render(img, ray_x, ray_y, i);
			ft_ceilling(img, i, t, ray);
			ft_floor(img, i, t, ray);
			break ;
		}
		t += .01;
	}
	return (t);
}

int			ft_ray(t_data *img)
{
	int		i;
	float	ray;

	i = -1;
	if (!(img->img = mlx_new_image(img->mlx, img->config->win_w, \
			img->config->win_h)))
		return (ft_exit(0, img));
	img->addr = mlx_get_data_addr(img->img, \
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!(img->t = (float*)malloc(sizeof(float) * (img->config->win_w + 1))))
		return (ft_exit(5, img));
	while (++i < img->config->win_w)
	{
		ray = img->player_a - img->fov / 2 + img->fov * i / \
				(float)(img->config->win_w);
		img->t[i] = ft_raycasting(img, ray, i);
	}
	ft_sprite(img);
	ft_minimap(img);
	ft_health(img);
	ft_hand(img);
	if (img->screen != 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	free(img->t);
	return (0);
}
