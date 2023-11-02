/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:13:01 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/25 18:20:29 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int				simb;
	int				i;
	long long		var;

	i = 0;
	simb = 1;
	var = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1 * simb;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		var = ((var * 10) + (str[i] - '0'));
		i++;
	}
	return (var * simb);
}
