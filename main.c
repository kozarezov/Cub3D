/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:03:22 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/13 11:35:37 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_param(t_conf *param, t_data *img)
{
	if (param->ceilling[0] == -1)
		return (ft_exit(4, img));
	if (param->floor[0] == -1)
		return (ft_exit(4, img));
	if (param->east == NULL)
		return (ft_exit(4, img));
	if (param->north == NULL)
		return (ft_exit(4, img));
	if (param->south == NULL)
		return (ft_exit(4, img));
	if (param->sprite == NULL)
		return (ft_exit(4, img));
	if (param->west == NULL)
		return (ft_exit(4, img));
	if (param->map_temp == NULL)
		return (ft_exit(4, img));
	if (param->win_h == 0)
		return (ft_exit(4, img));
	if (param->win_w == 0)
		return (ft_exit(4, img));
	return (1);
}

void			init_param(t_conf *param)
{
	param->ceilling[0] = -1;
	param->floor[0] = -1;
	param->east = NULL;
	param->north = NULL;
	param->south = NULL;
	param->sprite = NULL;
	param->west = NULL;
	param->map_temp = NULL;
	param->win_h = 0;
	param->win_w = 0;
}

int				ft_close(t_data *img)
{
	return (ft_exit(6, img));
}

int				main(int argc, char *argv[])
{
	t_data		*img;
	t_conf		*param;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
		return (0);
	}
	if (!(img = (t_data*)malloc(sizeof(t_data))))
		return (ft_exit(1, img));
	if (!(param = (t_conf*)malloc(sizeof(t_conf))))
		return (ft_exit(1, img));
	if (!(img->mlx = mlx_init()))
		return (ft_exit(0, img));
	img->config = param;
	config(param, img, argv[1]);
	check_param(param, img);
	if (!(img->mlx_win = mlx_new_window(img->mlx, img->config->win_w, \
		img->config->win_h, "Cub3D")))
		return (ft_exit(0, img));
	(argc == 3) ? ft_screenshot(img, argv[2]) : ft_ray(img);
	mlx_hook(img->mlx_win, 17, 1, ft_close, img);
	mlx_hook(img->mlx_win, 2, 0, ft_key, img);
	mlx_loop_hook(img->mlx, ft_shoot, img);
	mlx_loop(img->mlx);
}
