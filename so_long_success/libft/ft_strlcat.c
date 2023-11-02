/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:08:19 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/11 12:08:22 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!dest && n == 0)
	{
		return (0);
	}
	while (dest[i] && i < n)
	{
		i++;
	}
	while (src[x] && (i + x +1) < n)
	{
		dest[i + x] = src[x];
		x++;
	}
	if (i != n)
	{
		dest[i + x] = '\0';
	}
	return (i + ft_strlen(src));
}
