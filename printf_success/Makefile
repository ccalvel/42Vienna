# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:21:54 by ccaldero          #+#    #+#              #
#    Updated: 2022/11/15 16:22:12 by ccaldero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strlen.c \
			ft_dec_to_hex.c \
			ft_dec_to_hex_klein.c \
			ft_point_hex.c \
			

OBJECTS = $(SOURCES:.c=.o)

$(NAME): all

all:
	cc $(CFLAGS) -c $(SOURCES)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
