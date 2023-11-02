/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:28:19 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/21 15:28:20 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = str1;
	s2 = str2;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (0);
	while (n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	return ((char *)str1);
}
