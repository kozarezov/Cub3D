/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puck_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:54:12 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/11 17:10:09 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

unsigned int		ft_puck_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
