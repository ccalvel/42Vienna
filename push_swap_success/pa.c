/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:29:27 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/24 18:56:41 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_a > 0)
	{
		stack->size_b += 1;
		while (j < stack->size_b)
			j++;
		while (j > 0)
		{
			stack->stack_b[j] = stack->stack_b[j - 1];
			j--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		while (i < stack->size_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->size_a -= 1;
		write(1, "pb\n", 3);
	}
}

void	pa(t_list *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->size_b > 0)
	{
		stack->size_a += 1;
		while (j < stack->size_a)
			j++;
		while (j > 0)
		{
			stack->stack_a[j] = stack->stack_a[j - 1];
			j--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		while (i < stack->size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->size_b -= 1;
		write(1, "pa\n", 3);
	}
}
