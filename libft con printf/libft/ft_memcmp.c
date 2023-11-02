/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:44:25 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/11 13:44:27 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char	*s1;
	const char	*s2;
	size_t		i;

	s1 = str1;
	s2 = str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
