/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:59:38 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/12 10:52:24 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					what_side(t_data *img, float ray_x, float ray_y)
{
	int				side;

	side = 100;
	if (img->map[(int)(ray_x - .01) + (int)(ray_y) * img->config->map_w] == '.')
		side = 102;
	else if (img->map[(int)(ray_x + .01) + (int)(ray_y) * \
			img->config->map_w] == '.')
		side = 103;
	else if (img->map[(int)(ray_x) + (int)(ray_y - .01) * \
			img->config->map_w] == '.')
		side = 101;
	else if (img->map[(int)(ray_x) + (int)(ray_y + .01) * \
			img->config->map_w] == '.')
		side = 100;
	return (side);
}

void				put_texture_column(t_data *img, unsigned int *column, int i)
{
	int				pix_x;
	int				pix_y;
	int				j;

	j = 0;
	pix_x = i;
	while (j < img->column_h)
	{
		pix_y = j + img->config->win_h / 2 - img->column_h / 2;
		if (pix_y >= 0 && pix_y < img->config->win_h)
			my_mlx_pixel_put(img, pix_x, pix_y, column[j]);
		j++;
	}
}

void				take_col(t_data *img, int cord, \
unsigned int *column, int textid)
{
	int				pix_x;
	int				pix_y;
	int				j;

	j = 0;
	pix_x = cord;
	while (j < img->column_h)
	{
		pix_y = (j * TEXT_SIZE) / img->column_h;
		column[j] = ft_load_picture(img, pix_x, pix_y, textid);
		j++;
	}
}

int					ft_render(t_data *img, float ray_x, float ray_y, int i)
{
	float			hit_x;
	float			hit_y;
	int				cord;
	unsigned int	*column;

	if (!(column = (unsigned int*)malloc(sizeof(unsigned int) * \
		(img->column_h + 1))))
		return (ft_exit(5, img));
	hit_x = ray_x - floor(ray_x + .5);
	hit_y = ray_y - floor(ray_y + .5);
	cord = hit_x * TEXT_SIZE;
	if ((fabsf)(hit_y) > (fabsf)(hit_x))
		cord = hit_y * TEXT_SIZE;
	if (cord < 0)
		cord += TEXT_SIZE;
	take_col(img, cord, column, what_side(img, ray_x, ray_y));
	put_texture_column(img, column, i);
	free(column);
	return (0);
}
