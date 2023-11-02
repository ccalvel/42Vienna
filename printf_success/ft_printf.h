/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:14:18 by ccaldero          #+#    #+#             */
/*   Updated: 2022/11/15 15:14:23 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<stdarg.h>
# include<stdio.h>

int	ft_printf(const char *var, ...);
int	ft_putchar(char c);
int	ft_putstr(char const *str);
int	ft_putnbr(long long nb);
int	ft_dec_to_hex(unsigned int num);
int	ft_dec_to_hex_klein(unsigned int num);
int	ft_strlen(int str);
int	ft_point_hex(unsigned long long int num);

#endif
