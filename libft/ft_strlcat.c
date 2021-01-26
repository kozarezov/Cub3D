/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 09:58:31 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/08 09:58:32 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[j] != '\0')
		j++;
	while (dst[k] != '\0' && k < size)
		k++;
	if (size == 0)
		return (j);
	if (size <= k)
		return (j + size);
	while (i < (size - k - 1) && src[i] != '\0')
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (j + k);
}
