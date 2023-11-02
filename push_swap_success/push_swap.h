/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:14:44 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/26 19:30:52 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	size_prueba;
}t_list;

void		sa(t_list *info);
void		sb(t_list *info);
void		ra(t_list *info);
void		rb(t_list *info);
void		rra(t_list *info);
void		rrb(t_list *info);
void		pb(t_list *info);
void		pa(t_list *info);
int			algoritmos(t_list *stack);
void		alg_two_arg(t_list *stack);
void		alg_three_arg(t_list *stack);
void		alg_four_arg(t_list *stack);
void		alg_five_arg(t_list *stack);
int			minimum(t_list *stack);
int			algoritmos_big(t_list *stack);
void		ft_index(t_list *stack);
int			sorted(t_list *stack);
int			error_no_digit(char **argv, t_list stack);
int			error(int argc,	t_list stack);
void		write_error(char **argv, t_list stack);
int			ft_count_word(char const *str, char c);
void		free_split(char **split_argv);
long long	ft_atoll(const char *str);

#endif // PUSH_SWAP_H
