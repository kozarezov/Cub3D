/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 09:02:30 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/03 09:26:53 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (((unsigned char*)str)[i] != '\0')
	{
		if (((unsigned char*)str)[i] == (((unsigned char)ch)))
			return (((char*)str) + i);
		i++;
	}
	if (((unsigned char*)str)[i] == (((unsigned char)ch)))
		return (((char*)str) + i);
	return (NULL);
}
