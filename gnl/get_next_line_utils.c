/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 23:32:32 by ceccentr          #+#    #+#             */
/*   Updated: 2020/07/22 15:50:33 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin_gnl(char *s1, char *s2, int flag)
{
	size_t		size;
	size_t		i;
	size_t		j;
	char		*array;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[j])
			array[i++] = s1[j++];
		j = 0;
		while (s2[j])
			array[i++] = s2[j++];
		array[i] = '\0';
		if (flag && s1)
			free(s1);
		return (array);
	}
	return (NULL);
}
