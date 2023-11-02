/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:08:37 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/28 17:08:41 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		x;
	char		*str;
	int			var;

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
	return (str);
}
