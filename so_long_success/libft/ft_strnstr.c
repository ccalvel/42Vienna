/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:11:19 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/11 15:11:21 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		x;
	const char	*ptr;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	if (big == 0 && len == 0)
		return (0);
	while (big[i] != '\0' && i < len)
	{
		x = 0;
		ptr = &big[i];
		while (big[i + x] == little[x] && little[x] != 0 && x + i < len)
		{
			x++;
			if (little[x] == '\0')
				return ((char *) ptr);
		}
		i++;
	}
	return (0);
}
