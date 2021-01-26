/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:22:57 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/06 09:36:45 by Ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(long x)
{
	int count;

	count = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		count++;
		x = x * -1;
	}
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		i;
	long	x;

	x = n;
	i = len_num(x);
	if (!(dst = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	dst[i--] = '\0';
	if (x == 0)
		dst[0] = 0 + '0';
	if (x < 0)
	{
		dst[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		dst[i] = x % 10 + '0';
		x = x / 10;
		i--;
	}
	return (dst);
}
