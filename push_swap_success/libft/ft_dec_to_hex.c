/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:20:49 by ccaldero          #+#    #+#             */
/*   Updated: 2023/01/10 14:20:52 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_def(unsigned long long nb)
{
	static char	hexnmb[] = "0123456789ABCDEF";
	char		ptr;

	if (nb < 16)
	{
		ptr = hexnmb[nb];
		write (1, &ptr, 1);
	}
	if (nb >= 16)
	{
		ft_def (nb / 16);
		ft_def (nb % 16);
	}
}

int	ft_dec_to_hex(unsigned int nb)
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

/*int main()
{
    
    int ret = ft_dec_to_hex(16);
   // printf("\n%d\n", ret);
    //free(ptr);
} */
