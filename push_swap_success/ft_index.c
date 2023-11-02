/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:57:22 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/24 12:39:42 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(t_list *stack)
{
	int	i;
	int	small;
	int	j;

	i = 1;
	j = 0;
	small = stack->stack_a[0];
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < small)
		{
			small = stack->stack_a[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	make_index(t_list *stack)
{
	int	num;
	int	j;
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		num = 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[j] < stack->stack_a[i])
				num++;
			j++;
		}
		stack->stack_b[i] = num;
		i++;
	}
}

void	index_a(t_list *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		stack->stack_a[i] = stack->stack_b[i];
		stack->stack_b[i] = 0;
		i++;
	}
}

void	ft_index(t_list *stack)
{
	make_index(stack);
	index_a(stack);
}
