/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:51:36 by ccaldero          #+#    #+#             */
/*   Updated: 2022/12/19 15:51:45 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	defin_tipo(va_list args, const char str)
{
	int	var;

	var = 0;
	if (str == 'c')
		var += ft_putchar(va_arg(args, int));
	else if (str == 's')
		var += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		var += ft_putnbr(va_arg(args, int));
	else if (str == '%')
		var += ft_putchar('%');
	else if (str == 'X')
		var += ft_dec_to_hex(va_arg(args, unsigned int));
	else if (str == 'x')
		var += ft_dec_to_hex_klein(va_arg(args, unsigned int));
	else if (str == 'u')
		var += ft_putnbr(va_arg(args, unsigned int));
	else if (str == 'p')
		var += ft_point_hex(va_arg(args, unsigned long long));
	return (var);
}

int	ft_printf(const char *var, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start (args, var);
	i = 0;
	len = 0;
	while (var[i] != '\0')
	{
		if (var[i] == '%')
		{
			i++;
			len += defin_tipo(args, var[i]);
			i++;
		}
		else
		{
			len += ft_putchar(var[i]);
			i++;
		}
	}
	va_end (args);
	return (len);
}

/*
int main()
{
	char var = 'k';
	//char x = 'x';
	
	ft_printf("c: %c\n", var);
	printf("c: %c\n", var);
	char str[] = "Hallo";
	ft_printf("s: %s\n", str);
	printf("s: %s\n", str);
	int nbr = 1;
	ft_printf("d: %d\n", nbr);
	printf("d: %d\n", nbr);
	ft_printf("i: %i\n", nbr);
	printf("i: %i\n", nbr);
//	int perc = '%';
	ft_printf("%%: %%\n");
	printf("%%: %% \n");
	//int hex = 140736541956216;
	int hex= 333;
	ft_printf("x: %x\n", hex);
	printf("x: %x\n", hex);
	ft_printf("X: %X\n", hex);
	printf("X: %X\n", hex);
	int uns = -1000; 
	ft_printf("u: %u\n", uns);
	printf("u: %u\n", uns );
	int ptr = 333;	
	int *point = &ptr;
	//printf("p: %p value: %ld\n ", point, 140736541956216);
	ft_printf("p: %p value: %d\n", point, *point);
	//printf("p: %p value: %d\n ", ptr, ptr);
	ft_printf("p: %p value: %d\n", ptr, ptr);
	
	//printf(" %p \n%p\n\n ", LONG_MIN, LONG_MAX);
	//ft_printf(" %p \n%p ", LONG_MIN, LONG_MAX);
	
}
*/
