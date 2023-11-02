/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:14 by ccaldero          #+#    #+#             */
/*   Updated: 2022/10/29 19:17:24 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_def(int nb, int fd)
{
	char	var[12];
	int		i;
	int		x;

	i = 0;
	while (nb > 0)
	{
		var[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	x = i - 1;
	while (x >= 0)
	{
		write(fd, &var[x], 1);
		x--;
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == 0)
		write(fd, "0", 1);
	if (n > 0)
		ft_def(n, fd);
	if (n < 0 && n > -2147483648)
	{
		n = n * (-1);
		write(fd, "-", 1);
		ft_def(n, fd);
	}
}
