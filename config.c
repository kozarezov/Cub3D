/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:36:06 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/19 11:13:20 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_path(t_conf *param, char **buf)
{
	if (ft_strncmp(buf[0], "NO", 2) == 0)
		if (param->north != NULL)
			return (0);
	if (ft_strncmp(buf[0], "SO", 2) == 0)
	{
		if (param->south != NULL)
			return (0);
	}
	else if (ft_strncmp(buf[0], "S", 1) == 0)
		if (param->sprite != NULL)
			return (0);
	if (ft_strncmp(buf[0], "WE", 2) == 0)
		if (param->west != NULL)
			return (0);
	if (ft_strncmp(buf[0], "EA", 2) == 0)
		if (param->east != NULL)
			return (0);
	return (1);
}

int			ft_path(t_conf *param, char *line)
{
	char	**buf;
	int		i;

	i = 0;
	buf = ft_split(line, ' ');
	while (buf[i] != NULL)
		i++;
	if (i != 2 || ft_check_path(param, buf) == 0)
	{
		clear_buf(buf);
		return (0);
	}
	if (ft_strncmp(buf[0], "NO", 2) == 0)
		param->north = ft_strdup(buf[1]);
	if (ft_strncmp(buf[0], "SO", 2) == 0)
		param->south = ft_strdup(buf[1]);
	else if (ft_strncmp(buf[0], "S", 1) == 0)
		param->sprite = ft_strdup(buf[1]);
	if (ft_strncmp(buf[0], "WE", 2) == 0)
		param->west = ft_strdup(buf[1]);
	if (ft_strncmp(buf[0], "EA", 2) == 0)
		param->east = ft_strdup(buf[1]);
	clear_buf(buf);
	return (1);
}

int			ft_size_window(t_conf *param, char *line)
{
	int		i;
	char	**buf;

	i = 0;
	buf = ft_split(line, ' ');
	while (buf[i] != NULL)
		i++;
	if (i != 3)
	{
		clear_buf(buf);
		return (0);
	}
	if (param->win_w > 0)
		return (0);
	param->win_w = ft_atoi(buf[1]);
	if (param->win_w > 1440 || param->win_w < 512)
		param->win_w = 1440;
	if (param->win_h > 0)
		return (0);
	param->win_h = ft_atoi(buf[2]);
	if (param->win_h > 860 || param->win_h < 512)
		param->win_h = 900;
	clear_buf(buf);
	return (1);
}

int			ft_check_param(t_conf *param, char *line)
{
	int		i;
	int		err;

	i = -1;
	err = 1;
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		err = ft_path(param, line);
	else if (line[0] == 'R')
		err = ft_size_window(param, line);
	else if (line[0] == 'F' || line[0] == 'C')
		err = ft_color(param, line);
	else
	{
		while (line[++i] != '\0')
		{
			if (line[i] == '0' || line[i] == '1')
			{
				ft_map(param, line);
				break ;
			}
		}
	}
	if (err == 0)
		return (0);
	return (1);
}

int			config(t_conf *param, t_data *img, char *arg)
{
	char	*line;
	int		fd;

	init_param(param);
	fd = ft_check_wh(param, img, arg);
	img->hp = 100;
	img->hand = 106;
	img->fov = M_PI / 3;
	img->pic = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_check_param(param, line) == 0)
			return (ft_exit(4, img));
		free(line);
	}
	free(line);
	param->map_temp[param->map_w * param->map_h] = '\0';
	ft_parse_pos(img, param, param->sprite);
	ft_parse_map(param, img);
	img->map = ft_strdup(param->map_temp);
	img->rect_w = img->config->win_w / img->config->map_w / 4;
	img->rect_h = img->config->win_h / img->config->map_h / 4;
	close(fd);
	return (0);
}
