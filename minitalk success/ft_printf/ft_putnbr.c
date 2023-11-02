/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:37:09 by ccaldero          #+#    #+#             */
/*   Updated: 2023/01/26 11:37:11 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_def(unsigned int nb)
{
	char	var;

	if (nb < 10)
	{
		var = nb + '0';
		write (1, &var, 1);
	}
	else
	{
		ft_def(nb / 10);
		ft_def(nb % 10);
	}
}

int	ft_putnbr(long long nb)
{
	int	ret;

	ret = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		ret++;
		nb = nb * (-1);
	}
	else
		ret = 0;
	if (nb == 0)
		ret++;
	ft_def(nb);
	while (nb != 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}
