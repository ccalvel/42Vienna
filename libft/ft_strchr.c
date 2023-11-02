/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:35:30 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/11 14:35:32 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int var)
{
	int			i;
	char		str2;

	str2 = (unsigned char) var;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str2)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == str2)
	{
		return ((char *)str + i);
	}
	return (0);
}
