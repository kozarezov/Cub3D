/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:56:41 by Ceccentr          #+#    #+#             */
/*   Updated: 2020/05/11 14:37:09 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clean_w(char **word, int j)
{
	while (j > 0)
	{
		j--;
		free(word[j]);
	}
	free(word);
	return (NULL);
}

static int	ft_count_w(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			if (flag == 0)
				flag = 1;
		}
		if (flag == 1)
		{
			count++;
			flag = 0;
		}
	}
	return (count);
}

static int	ft_count_l(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**word;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(word = (char**)malloc(sizeof(char*) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && j < ft_count_w(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(word[j] = (char*)malloc(sizeof(char) * ft_count_l(s, c, i) + 1)))
			return (clean_w(word, j));
		while (s[i] != c && s[i] != '\0')
			word[j][k++] = s[i++];
		word[j][k] = '\0';
		j++;
	}
	word[j] = NULL;
	return (word);
}
