/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 09:58:13 by ceccentr          #+#    #+#             */
/*   Updated: 2020/05/12 08:29:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dst;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
		return (ft_strdup(""));
	if ((i - start) < len)
		len = i - start;
	if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
