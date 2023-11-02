/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:27:52 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/28 13:27:56 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int var)
{
	int				i;
	const char		*str2;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == var)
		{
			str2 = &str[i];
			return ((char *)str2);
		}
		i++;
	}
	if (var == '\0')
	{
		str2 = &str[i];
		return ((char *)str2);
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char			*dest;
	int				i;
	int				x;

	i = 0;
	x = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		len = 0;
	if (len > (ft_strlen(s)-start))
	{
		dest = (char *)malloc(ft_strlen(s) - start + 1);
	}
	else
		dest = malloc(len +1);
	if (!dest)
		return (NULL);
	while (len > 0 && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			x;
	char			*str;
	int				var;

	var = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (var + 1));
	i = 0;
	x = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		str[i] = s2[x];
		i++;
		x++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
