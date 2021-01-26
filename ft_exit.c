/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:39:37 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/12 11:34:54 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_data *img, int keycode)
{
	if (keycode > 4)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		free(img->map);
	}
	free(img);
}

void	clear_pic(t_pic *pic, int keycode)
{
	t_pic	*temp;

	if (keycode != 2 && keycode != -1)
	{
		while (pic != NULL)
		{
			temp = pic->next;
			free(pic);
			pic = temp;
		}
	}
}

void	clear_config(t_conf *param, int keycode)
{
	if (keycode != -1)
	{
		free(param->north);
		free(param->south);
		free(param->west);
		free(param->east);
		free(param->sprite);
		free(param);
	}
}

void	ft_error(int keycode, t_data *img)
{
	if (keycode == 0)
	{
		ft_putstr_fd("Error\nError MLX function\n", 1);
		clear_pic(img->pic, keycode);
		clear_config(img->config, keycode);
		exit(0);
	}
	if (keycode == 1)
	{
		ft_putstr_fd("Error\nMemory is not allocated\n", 1);
		clear_img(img, keycode);
		exit(0);
	}
	if (keycode == 2 || keycode == -1)
		ft_putstr_fd("Error\nFailed to create/open file\n", 1);
	if (keycode == 3)
		ft_putstr_fd("Error\nMap is not valid\n", 1);
	if (keycode == 4)
		ft_putstr_fd("Error\nError in parameters\n", 1);
	if (keycode == 5)
		ft_putstr_fd("Error\nMemory is not allocated\n", 1);
	if (keycode == -2)
		ft_putstr_fd("Error\nInvalid argument\n", 1);
	else
		ft_putstr_fd("Goodbye!!!\n", 1);
}

int		ft_exit(int keycode, t_data *img)
{
	ft_error(keycode, img);
	clear_pic(img->pic, keycode);
	clear_config(img->config, keycode);
	clear_img(img, keycode);
	exit(0);
}
