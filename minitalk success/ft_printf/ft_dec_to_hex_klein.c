/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex_klein.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:08:24 by ccaldero          #+#    #+#             */
/*   Updated: 2023/01/11 15:08:37 by ccaldero         ###   ########.fr       */
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

int	ft_dec_to_hex_klein(unsigned int nb)
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

/*
int main()
{
    
    int ret = ft_dec_to_hex_klein(555);
   // printf("\n%d\n", ret);
    //free(ptr);
} 
*/
