/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:55:28 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/14 15:55:39 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int var, size_t count)
{
	while (count--)
	{
		if (*(unsigned char *)str == (unsigned char)var)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
