/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:40:00 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/19 10:53:56 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_valid(t_conf *param, char *arr, int i, int j)
{
	int		ret_n;
	int		ret_s;
	int		ret_w;
	int		ret_e;

	if (i == -1 || j == -1 || arr[i] == 0 || i == param->map_w || \
		arr[i + j * param->map_w] == 0)
		return (32);
	if (arr[i + j * param->map_w] != '0' && arr[i + j * param->map_w] != '2')
		return (arr[i + j * param->map_w]);
	param->map_temp[i + j * param->map_w] = '.';
	ret_e = ft_valid(param, arr, i, j + 1);
	ret_w = ft_valid(param, arr, i, j - 1);
	ret_n = ft_valid(param, arr, i + 1, j);
	ret_s = ft_valid(param, arr, i - 1, j);
	if (ret_n == 32 || ret_s == 32 || ret_w == 32 || ret_e == 32)
		return (32);
	return (1);
}

int			ft_parse_map(t_conf *param, t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < param->map_w)
	{
		j = 0;
		while (j < param->map_h)
		{
			if (param->map_temp[i + j * param->map_w] == '0')
			{
				if (ft_valid(param, param->map_temp, i, j) == 32)
					return (ft_exit(3, img));
			}
			j++;
		}
		i++;
	}
	return (1);
}
