NAME = so_long

#SO_LONG = so_long

SOURCES = so_long.c \
			check_args.c \
			get_next_line.c \
			maps.c \
			window.c \
			init_images.c \
			init_player_pos.c \
			validate_game_map.c \
			destroy.c \
			check_map.c \
			check_how_much.c \
			redraw_game.c \
			move_player.c \
			

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf

LIBFT = ./libft/libft.a
MLX = -lmlx -lXext -lX11 

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX) $(LIBFT) -o so_long
#	@$(CC) $(OBJECTS) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(SO_LONG)

clean: 
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJECTS)

fclean:	clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all
