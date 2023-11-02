/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:56:54 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/27 14:56:57 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

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
