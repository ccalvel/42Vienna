/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:42:11 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/25 13:11:12 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sorted(t_list *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a -1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	write_error(char **argv, t_list stack)
{
	write(2, "Error\n", 7);
	free_split(argv);
	free(stack.stack_a);
	exit(1);
}

int	error_one_arg(int argc, t_list stack)
{
	if (stack.size_a == 1 || argc <= 1)
	{
		free(stack.stack_a);
		exit(1);
	}
	if (stack.size_a == 0)
	{
		write(2, "Error", 5);
		write(2, "\n", 1);
		free(stack.stack_a);
		exit(1);
	}
	return (0);
}

int	error_duplicated(t_list stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.size_a -1)
	{
		j = i + 1;
		while (j <= stack.size_a -1)
		{
			if (stack.stack_a[i] == stack.stack_a[j])
			{
				write(2, "Error", 5);
				write(2, "\n", 1);
				free(stack.stack_a);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error(int argc, t_list stack)
{
	error_one_arg(argc, stack);
	error_duplicated(stack);
	if (sorted(&stack) == 1)
	{
		free(stack.stack_a);
		exit(1);
	}
	return (0);
}
