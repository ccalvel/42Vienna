/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:35:03 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/10 13:35:06 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	char		*ls1;
	const char	*ls2;

	s1 = dest;
	s2 = src;
	if (!dest && !src)
		return (0);
	if (s1 < s2)
	{
		while (n--)
			*s1++ = *s2++;
	}
	else
	{
		ls1 = s1 +(n - 1);
		ls2 = s2 +(n - 1);
		while (n--)
			*ls1-- = *ls2--;
	}
	return (dest);
}
