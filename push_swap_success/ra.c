/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:14:46 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/24 18:51:17 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list *stack)
{
	int	temp;
	int	i;

	temp = stack->stack_a[0];
	i = 0;
	while (i < stack->size_a -1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_list *stack)
{
	int	temp;
	int	i;

	temp = stack->stack_b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_list *stack)
{
	ra(stack);
	rb(stack);
}
