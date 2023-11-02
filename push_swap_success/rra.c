/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:33:23 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/24 18:50:54 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_list *stack)
{
	int	temp;
	int	i;

	i = 0;
	while (i < stack ->size_a -1)
		i++;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_list *stack)
{
	int	temp;
	int	i;

	i = 0;
	while (i < stack->size_b -1)
		i++;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_list *stack)
{
	rra(stack);
	rrb(stack);
}
