/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 09:30:17 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/03 09:30:40 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (((unsigned char*)str)[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (((unsigned char*)str)[i] == (((unsigned char)ch)))
			return (((char*)str) + i);
		i--;
	}
	return (NULL);
}
