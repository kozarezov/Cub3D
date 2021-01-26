/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:31:07 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/11 10:31:53 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sort_sprite(float *dist, int *sort, int num_sprite)
{
	int			i;
	int			j;
	int			tmp;
	float		temp;

	i = 0;
	while (i < num_sprite - 1)
	{
		j = num_sprite - 1;
		while (j > i)
		{
			if (dist[j - 1] > dist[j])
			{
				tmp = sort[j - 1];
				sort[j - 1] = sort[j];
				sort[j] = tmp;
				temp = dist[j - 1];
				dist[j - 1] = dist[j];
				dist[j] = temp;
			}
			j--;
		}
		i++;
	}
}

int				ft_sort(t_data *img, float *dist, int *sort)
{
	int			num_sprite;
	t_pic		*sprite;

	num_sprite = 0;
	while (1)
	{
		if (!(sprite = ft_search_texture_id(img, num_sprite)))
			break ;
		dist[num_sprite] = sqrt(pow(img->player_x - sprite->sprite_x, 2) + \
				pow(img->player_y - sprite->sprite_y, 2));
		sort[num_sprite] = num_sprite;
		num_sprite++;
	}
	sort_sprite(dist, sort, num_sprite);
	return (num_sprite);
}
