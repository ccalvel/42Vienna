# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:21:17 by ccaldero          #+#    #+#              #
#    Updated: 2023/05/25 19:25:22 by ccaldero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

LIBFT = ./libft/libft.a
PUSH_SWAP = push_swap

SOURCES = push_swap.c \
			sa.c \
			ra.c \
			rra.c \
			pa.c \
			error_push_swap.c \
			algoritmos.c \
			ft_count.c\
			error_no_digit.c \
			free_split.c \
			ft_atoll.c \
			ft_index.c\
			algoritmos_big.c \
			call_algoritmos.c\



OBJECTS = $(SOURCES:.c=.o)

all: $(PUSH_SWAP) 

$(LIBFT):
		@$(MAKE) -C ./libft

$(PUSH_SWAP): $(OBJECTS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(PUSH_SWAP)


clean: 
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJECTS) 

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(PUSH_SWAP) 

re: fclean all
