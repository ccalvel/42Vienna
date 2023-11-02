/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:01:58 by ccaldero          #+#    #+#             */
/*   Updated: 2023/04/20 11:02:01 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	handler(int signal)
{
	static int		bit = 0;
	static int		message = 0;

	if (signal == SIGUSR1)
	{
		message |= (1 << bit);
	}
	else if (signal == SIGUSR2)
	{
		message &= ~(1 << bit);
	}
	else
	{
		return ;
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", message);
		bit = 0;
		message = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error.\n");
		return (1);
	}
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
