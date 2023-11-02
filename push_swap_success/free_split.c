/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:01:37 by ccaldero          #+#    #+#             */
/*   Updated: 2023/05/23 16:35:21 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_argv)
{
	int	i;

	i = 0;
	if (split_argv != NULL)
	{
		i = 0;
		while (split_argv[i])
		{
			free(split_argv[i]);
			i++;
		}
		free(split_argv);
	}
}
