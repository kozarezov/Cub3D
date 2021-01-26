/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:38:51 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/05 10:47:21 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(dst = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strlcpy(dst, s1, (len_s1 + 1));
	ft_strlcat(dst, s2, (len_s1 + len_s2 + 1));
	return (dst);
}
