/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:57:09 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/04/30 17:11:40 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src1)[i] != ((unsigned char*)src2)[i])
		{
			return (((unsigned char*)src1)[i] - ((unsigned char*)src2)[i]);
		}
		i++;
	}
	return (0);
}
