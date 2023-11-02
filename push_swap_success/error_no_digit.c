/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_no_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:01:55 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/25 17:53:50 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_numeric(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_single_plus_minus(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 1 && (argv[i][0] == '-' || argv[i][0] == '+'))
			return (1);
		i++;
	}
	return (0);
}

int	error_max_min_int(char **argv)
{
	int				i;
	long long		var;

	i = 0;
	while (argv[i])
	{
		var = ft_atoll(argv[i]);
		if (var < -2147483648 || var > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	error_zero(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (argv[i][j +1] == '0')
				{
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error_no_digit(char **argv, t_list stack)
{
	if (ft_is_numeric (argv) == 1)
		write_error(argv, stack);
	if (ft_single_plus_minus (argv) == 1)
		write_error(argv, stack);
	if (error_max_min_int (argv) == 1)
		write_error(argv, stack);
	if (error_zero (argv) == 1)
		write_error(argv, stack);
	return (0);
}
