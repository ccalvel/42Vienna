/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmos_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:04:13 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/26 18:11:31 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	radix_b(t_list *stack, int size_b, int bits, int i)
{
	while (size_b-- && i <= bits)
	{
		if (((stack->stack_b[0] >> i) & 1) == 0)
			rb(stack);
		else
			pa(stack);
	}
}

int	bit_size(t_list *stack, int bits)
{
	while (stack->size_prueba > 1)
	{
		stack->size_prueba /= 2;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_list *stack)
{
	int	i;
	int	bits;

	bits = 0;
	stack->size_prueba = stack->size_a;
	bits = bit_size(stack, bits);
	i = 0;
	while (i <= bits)
	{
		stack->size_prueba = stack->size_a ;
		while (stack->size_prueba-- && sorted(stack) == 0)
		{
			if (((stack->stack_a[0] >> i) & 1) == 0)
				pb(stack);
			else
				ra(stack);
		}
		radix_b(stack, stack->size_b, bits, i + 1);
		i++;
	}
	while (stack->size_b != 0)
		pa(stack);
}

int	algoritmos_big(t_list *stack)
{
	if (stack->size_a > 5)
	{
		ft_index(stack);
		radix_sort(stack);
	}
	return (0);
}
