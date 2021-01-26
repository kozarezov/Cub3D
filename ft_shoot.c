/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:14:20 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/21 10:54:09 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_shoot(t_data *img)
{
	int				i;

	i = 0;
	if (img->hand == 107)
	{
		while (i < 100000000)
			i++;
		img->hand = 106;
		mlx_destroy_image(img->mlx, img->img);
		ft_ray(img);
	}
	return (0);
}
