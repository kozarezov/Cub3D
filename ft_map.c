/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:08:53 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/19 11:23:49 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_map(t_conf *param, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		param->map_temp[i + param->map_h * param->map_w] = line[i];
		i++;
	}
	while (i < param->map_w)
	{
		param->map_temp[i + param->map_h * param->map_w] = ' ';
		i++;
	}
	param->map_h++;
	return (1);
}
