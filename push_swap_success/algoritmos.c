/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:46:48 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/26 19:30:21 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_two_arg(t_list *stack);
void	alg_three_arg(t_list *stack);
void	alg_four_arg(t_list *stack);

int	auxiliar(t_list *stack)
{
	if (stack->size_a == 5)
	{
		pb(stack);
		alg_four_arg(stack);
		pa(stack);
	}
	if (stack->size_a == 4)
	{
		pb(stack);
		alg_three_arg(stack);
		pa(stack);
	}
	if (stack->size_a == 3)
	{
		pb(stack);
		alg_two_arg(stack);
		pa(stack);
	}
	return (0);
}

void	alg_five_arg(t_list *stack)
{
	int	j;

	j = minimum(stack);
	if (stack->size_a == 5)
	{
		if (j == 1)
		{
			ra(stack);
		}
		if (j == 2)
		{
			rra(stack);
			rra(stack);
			rra(stack);
		}
		if (j == 3)
		{
			rra(stack);
			rra(stack);
		}
		if (j == 4)
			rra(stack);
		auxiliar(stack);
	}
}

void	alg_four_arg(t_list *stack)
{
	int	j;

	j = minimum(stack);
	if (stack->size_a == 4)
	{
		if (j == 1)
		{
			ra(stack);
		}
		if (j == 2)
		{
			rra(stack);
			rra(stack);
		}
		if (j == 3)
		{
			rra(stack);
		}
		auxiliar(stack);
	}
}

void	alg_three_arg(t_list *stack)
{
	int	j;

	j = minimum(stack);
	if (stack->size_a == 3)
	{
		if (j == 1)
		{
			ra(stack);
			if (stack->stack_a[1] > stack->stack_a[2])
			{
				rra(stack);
				sa(stack);
			}
		}
		else if (j == 2)
		{
			rra(stack);
			if (stack->stack_a[1] > stack->stack_a[2])
				rra(stack);
			if (stack->stack_a[0] > stack->stack_a[1])
				sa(stack);
		}
		else
			auxiliar(stack);
	}
}

void	alg_two_arg(t_list *stack)
{
	int	i;

	i = 0;
	if (stack->size_a == 2)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			sa(stack);
	}
}
