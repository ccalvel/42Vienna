/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algoritmos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:54:41 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/25 16:58:23 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	algoritmos(t_list *stack)
{
	alg_two_arg(stack);
	alg_three_arg(stack);
	alg_four_arg(stack);
	alg_five_arg(stack);
	return (0);
}
