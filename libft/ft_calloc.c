/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:06:19 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/04 12:23:40 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = malloc(num * size);
	if (!dst)
		return (NULL);
	while (i < (num * size))
	{
		dst[i] = 0;
		i++;
	}
	return ((void*)dst);
}
