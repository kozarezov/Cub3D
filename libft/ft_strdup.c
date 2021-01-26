/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 07:26:19 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/05 07:39:27 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = str[j];
	return (dst);
}
