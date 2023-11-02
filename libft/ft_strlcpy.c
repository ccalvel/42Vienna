/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:33 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/25 14:02:35 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (src[i] != '\0')
		i++;
	if (n == 0)
		return (i);
	while (n -1 > 0 && src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
		n--;
	}
	dest[x] = '\0';
	return (i);
}
