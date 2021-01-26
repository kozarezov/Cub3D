/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:50:14 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/21 10:53:24 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		left_and_right(int keycode, t_data *img)
{
	float	temp_x;
	float	temp_y;

	temp_x = img->player_x;
	temp_y = img->player_y;
	if (keycode == A)
	{
		img->player_x = img->player_x + cos(img->player_a - M_PI / 2) * SPEED;
		img->player_y = img->player_y + sin(img->player_a - M_PI / 2) * SPEED;
	}
	if (keycode == D)
	{
		img->player_x = img->player_x - cos(img->player_a - M_PI / 2) * SPEED;
		img->player_y = img->player_y - sin(img->player_a - M_PI / 2) * SPEED;
	}
	if (ft_check_wall(img) == 10)
	{
		img->player_x = temp_x;
		img->player_y = temp_y;
	}
	mlx_destroy_image(img->mlx, img->img);
	ft_ray(img);
}

void		up_and_down(int keycode, t_data *img)
{
	float	temp_x;
	float	temp_y;

	temp_x = img->player_x;
	temp_y = img->player_y;
	if (keycode == W)
	{
		img->player_x = img->player_x + cos(img->player_a) * SPEED;
		img->player_y = img->player_y + sin(img->player_a) * SPEED;
	}
	if (keycode == S)
	{
		img->player_x = img->player_x - cos(img->player_a) * SPEED;
		img->player_y = img->player_y - sin(img->player_a) * SPEED;
	}
	if (ft_check_wall(img) == 10)
	{
		img->player_x = temp_x;
		img->player_y = temp_y;
	}
	mlx_destroy_image(img->mlx, img->img);
	ft_ray(img);
}

void		owerwiew(int keycode, t_data *img)
{
	if (keycode == RIGHT)
	{
		if (img->player_a >= 2 * M_PI)
			img->player_a = 0;
		img->player_a = img->player_a + SPEED * M_PI / 10;
		mlx_destroy_image(img->mlx, img->img);
		ft_ray(img);
	}
	if (keycode == LEFT)
	{
		if (img->player_a <= 0.1)
			img->player_a = 2 * M_PI;
		img->player_a = img->player_a - SPEED * M_PI / 10;
		mlx_destroy_image(img->mlx, img->img);
		ft_ray(img);
	}
}

int			ft_key(int keycode, t_data *img)
{
	if (keycode == ESC)
		return (ft_exit(6, img));
	if (keycode == LEFT || keycode == RIGHT)
		owerwiew(keycode, img);
	if (keycode == W || keycode == S)
		up_and_down(keycode, img);
	if (keycode == A || keycode == D)
		left_and_right(keycode, img);
	if (keycode == SPACE)
	{
		img->hand = 107;
		mlx_destroy_image(img->mlx, img->img);
		ft_ray(img);
	}
	return (0);
}
