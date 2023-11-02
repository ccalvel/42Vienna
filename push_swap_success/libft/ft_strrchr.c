/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:59:03 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/14 15:59:13 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int var)
{
	size_t	i;

	i = ft_strlen (s);
	while (i > 0)
	{
		if (s[i] == (char)var)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (char)var)
		return ((char *)s + i);
	else
		return (NULL);
}
