/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:11:40 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/20 13:52:12 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *game)
{
	game->img_wall = NULL;
	game->img_player = NULL;
	game->player_pos = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->len = 0;
	game->num_lines = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_width = 0;
	game->img_height = 0;
	game->num_collectibles = 0;
	game->reached_exit = 0;
	game->is_valid_map = 0;
}

void	init_game(t_game *game)
{
	if (game->is_valid_map)
		game->mlx = mlx_init();
	else
	{
		destroy_game(game);
		exit(1);
	}
	if (game->mlx == NULL)
	{
		destroy_game(game);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		exit(1);
	}
	init_var(game);
	check_arg(argc, argv, game);
	read_map(argv[1], game);
	check_map(game);
	check_collectibles_to_exit(game);
	check_how_much(game);
	validate_game_map(game);
	init_game(game);
	open_window(game);
	init_images(game);
	update_player_pos(game);
	redraw_game(game);
	mlx_key_hook(game->mlx_win, press_key, game);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	destroy_game(game);
	return (0);
}
