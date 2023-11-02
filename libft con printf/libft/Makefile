# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 16:00:37 by ccaldero          #+#    #+#              #
#    Updated: 2022/11/14 16:00:45 by ccaldero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memmove.c\
		ft_strlcat.c \
		ft_toupper.c\
		ft_tolower.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_memcpy.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strtrim.c \
	    ft_strrchr.c \
		ft_memchr.c \
		ft_split.c \
		ft_memcmp.c \
		ft_strnstr.c \

SOURCES_PRINTF = ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strlen_pf.c \
			ft_dec_to_hex.c \
			ft_dec_to_hex_klein.c \
			ft_point_hex.c \

OBJECTS = $(SOURCES:.c=.o) $(SOURCES_PRINTF:.c=.o)

$(NAME): all

all:

	cc $(CFLAGS) -c $(SOURCES) $(SOURCES_PRINTF)
	ar rcs $(NAME) $(OBJECTS)

clean:

	@$(RM) $(OBJECTS)

fclean: clean

	@$(RM) $(NAME)

re: fclean all
