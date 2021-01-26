/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:03:13 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/04/30 11:07:41 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
