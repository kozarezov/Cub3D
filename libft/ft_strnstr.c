/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:40:37 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/07 09:19:34 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char*)big);
	while (i < len && big[i] != '\0')
	{
		if (lit[0] == big[i])
		{
			j = 0;
			while (lit[j] == big[i + j] && (i + j) < len)
			{
				j++;
				if (lit[j] == '\0')
					return ((char*)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
