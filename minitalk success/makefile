# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaldero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 11:03:00 by ccaldero          #+#    #+#              #
#    Updated: 2023/04/20 11:03:07 by ccaldero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Names
SERVER = server
CLIENT = client

#Directories
LIBFT_DIR = ft_printf

#Source
SRC_CLIENT = client.c
SRC_SERVER = server.c
HEADER = ft_minitalk.h 

#Object
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

#Libraries
LIBFT = $(LIBFT_DIR)/libftprintf.a
#LIB_INC = -I $(LIBFT_DIR)/includes

#Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

#Rules
$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_INC) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_INC) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	
#%.o: %.c $(INC)
#	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

#.PHONY: all clean fclean re
