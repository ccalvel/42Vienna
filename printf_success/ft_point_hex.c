/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:05:49 by ccaldero          #+#    #+#             */
/*   Updated: 2023/01/12 14:05:52 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_def(unsigned long long nb)
{
	static char	hexnmb[] = "0123456789abcdef";
	char		ptr;

	if (nb < 16)
	{
		ptr = hexnmb[nb];
		write (1, &ptr, 1);
	}
	if (nb >= 16)
	{
		ft_def(nb / 16);
		ft_def(nb % 16);
	}
}

static int	ft_dec_to_hex_point(unsigned long long nb)
{
	unsigned long long	ret;

	ret = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	ft_def(nb);
	while (nb != 0)
	{
		nb /= 16;
		ret++;
	}
	return (ret);
}

static int	ft_strlen_point(unsigned long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

int	ft_point_hex(unsigned long long num)
{
	if (num == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	ft_putchar ('0');
	ft_putchar ('x');
	ft_dec_to_hex_point(num);
	return (ft_strlen_point(num) + 2);
}

/*
int main()
{
int x = 555;
int *ptr= &x;

printf("p: %p\n", ft_hexptr(x));
}
*/
