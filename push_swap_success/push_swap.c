/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:26:48 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/26 17:05:43 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	swap_split(int argc, char **argv)
{
	int			i;
	int			j;
	int			x;
	char		**split_argv;

	i = 1;
	x = 0;
	while (i < argc)
	{
		j = 0;
		split_argv = ft_split(argv[i], ' ');
		x += ft_count_word(argv[i], ' ');
		while (split_argv[j])
		{
			free(split_argv[j]);
			j++;
		}
		free(split_argv);
		i++;
	}
	return (x);
}

void	getnumbers(int argc, char **argv, t_list stack)
{
	int			i;
	int			j;
	int			k;
	char		**split_argv;

	k = 1;
	i = 0;
	while (k < argc)
	{
		j = 0;
		split_argv = ft_split(argv[k], ' ');
		error_no_digit(split_argv, stack);
		while (split_argv[j])
		{
			stack.stack_a[i] = ft_atoi(split_argv[j]);
			i++;
			j++;
		}
		free_split(split_argv);
		split_argv = NULL;
		k++;
	}
}

int	main(int argc, char **argv)
{
	t_list	stack;

	stack.size_a = swap_split(argc, argv);
	stack.size_b = 0;
	stack.stack_a = (int *)malloc((sizeof(int) * stack.size_a) + 16);
	if (!stack.stack_a)
	{
		free(stack.stack_a);
		exit(1);
	}
	getnumbers(argc, argv, stack);
	error(argc, stack);
	stack.stack_b = (int *)malloc((sizeof(int) * stack.size_a) + 16);
	if (!stack.stack_b)
	{
		free(stack.stack_a);
		free(stack.stack_b);
		exit(1);
	}
	algoritmos(&stack);
	algoritmos_big(&stack);
	free(stack.stack_b);
	free(stack.stack_a);
}
