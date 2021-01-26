/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:21:54 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/13 11:17:05 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_color_rec(t_conf *param, char **buf, char *temp)
{
	int		i;

	i = 0;
	if (ft_strncmp(temp, "F", 1) == 0)
	{
		if (param->floor[0] != -1)
			return (0);
		while (i < 3)
		{
			param->floor[i] = ft_atoi(buf[i]);
			i++;
		}
	}
	if (ft_strncmp(temp, "C", 1) == 0)
	{
		if (param->ceilling[0] != -1)
			return (0);
		while (i < 3)
		{
			param->ceilling[i] = ft_atoi(buf[i]);
			i++;
		}
	}
	return (1);
}

int			count_buf(char **temp)
{
	int		i;

	i = 0;
	while (temp[i] != NULL)
		i++;
	return (i);
}

int			ft_color(t_conf *param, char *line)
{
	char	**buf;
	char	**temp;

	temp = ft_split(line, ' ');
	if (count_buf(temp) != 2)
	{
		clear_buf(temp);
		return (0);
	}
	buf = ft_split(temp[1], ',');
	if (count_buf(buf) != 3)
	{
		clear_buf(buf);
		return (0);
	}
	if (ft_color_rec(param, buf, temp[0]) == 0)
		return (0);
	clear_buf(temp);
	clear_buf(buf);
	return (1);
}
