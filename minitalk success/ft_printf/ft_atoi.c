/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:50:32 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/17 12:50:34 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	simb;
	int	i;
	int	var;

	simb = 1;
	i = 0;
	var = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			simb = -1 * simb;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		var = (str[i] - '0') + (var * 10);
		i++;
	}
	return (var * simb);
}
