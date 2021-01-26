/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:58:30 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/06 15:05:01 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	if (n == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		}
	}
	return (dst);
}
