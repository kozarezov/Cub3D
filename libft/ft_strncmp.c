/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:40:00 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/06 08:24:44 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (((unsigned char*)str1)[i] != ((unsigned char*)str2)[i])
		{
			return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
		}
		i++;
	}
	if (i != n)
		return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
	return (0);
}
