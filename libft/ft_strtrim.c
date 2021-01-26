/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:07:06 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/10 10:37:35 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			trim_move(char ch, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			finish;
	char			*dst;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (trim_move(s1[start], set) != 0 && s1[start] != '\0')
		start++;
	finish = ft_strlen(s1) - 1;
	while (trim_move(s1[finish], set) != 0)
		finish--;
	dst = ft_substr(s1, start, (finish - start + 1));
	return (dst);
}
