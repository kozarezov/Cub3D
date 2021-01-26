/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:07:17 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/12 10:52:49 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		screen_pixel_take(t_data *data, int x, int y)
{
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int					bmp_header(int fd, int h, int w, int padsize)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (w * 3 * h) + (padsize * h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int					bmp_data(int fd, t_data *img, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = img->config->win_h - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < img->config->win_w)
		{
			pixel = screen_pixel_take(img, x, y);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int					take_screenshot(t_data *img)
{
	int				padsize;
	int				fd;

	ft_ray(img);
	padsize = (4 - ((int)img->config->win_w * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | \
			O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, img->config->win_h, img->config->win_w, padsize);
	bmp_data(fd, img, padsize);
	close(fd);
	return (1);
}

int					ft_screenshot(t_data *img, char *str)
{
	if (ft_strncmp("--save", str, 7) != 0)
		return (ft_exit(-2, img));
	img->screen = 1;
	if (!take_screenshot(img))
		return (ft_exit(-1, img));
	return (ft_exit(6, img));
}
