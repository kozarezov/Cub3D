/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:25:42 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/06 10:28:02 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (!(dst = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
