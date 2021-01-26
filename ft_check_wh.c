/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:18:18 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/19 10:14:13 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_wh(t_conf *param, char *line)
{
	int		i;

	i = 0;
	if (ft_isalpha(line[0]))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
		{
			if (param->map_w < (int)ft_strlen(line))
				param->map_w = (int)ft_strlen(line);
			param->map_h++;
			break ;
		}
		i++;
	}
	return (0);
}

int			ft_check_wh(t_conf *param, t_data *img, char *arg)
{
	char	*line;
	int		fd;

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (ft_exit(-1, img));
	param->map_h = 0;
	param->map_w = 0;
	while (get_next_line(fd, &line))
	{
		check_wh(param, line);
		free(line);
	}
	free(line);
	if (!(param->map_temp = (char*)malloc(sizeof(char) *\
		(param->map_h * param->map_w + 1))))
		return (ft_exit(5, img));
	param->map_h = 0;
	close(fd);
	if ((fd = open(arg, O_RDONLY)) < 0)
		return (ft_exit(-1, img));
	return (fd);
}
