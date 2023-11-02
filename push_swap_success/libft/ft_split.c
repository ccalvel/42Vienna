/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:22:23 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/09 19:28:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str && str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**str2;
	int		size;
	int		x;

	i = 0;
	x = -1;
	word = ft_count_word(s, c);
	str2 = (char **)malloc((word + 1) * sizeof(char *));
	if (!str2)
		return (NULL);
	while (++x < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		str2[x] = ft_substr(s, i, size);
		i += size;
	}
	str2[x] = NULL;
	return (str2);
}
