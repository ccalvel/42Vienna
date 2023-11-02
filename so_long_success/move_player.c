/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:53:24 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/28 15:16:04 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(int keycode)
{
	static int	count_moves;

	if (count_moves == 0)
		count_moves = 0;
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		count_moves++;
		ft_printf("Moves: %d\n", count_moves);
	}
}

void	new_position(t_game *game, int *new_x, int *new_y, int keycode)
{
	if (keycode == KEY_UP && game->player_x - 1 >= 0)
		*new_x = game->player_x - 1;
	if (keycode == KEY_DOWN && game->player_x + 1 < game->num_lines)
		*new_x = game->player_x + 1;
	if (keycode == KEY_LEFT && game->player_y - 1 >= 0)
		*new_y = game->player_y - 1;
	if (keycode == KEY_RIGHT && game->player_y + 1 < game->len)
		*new_y = game->player_y + 1;
}

void	check_next_tile(char next_tile, t_game *game, int new_x, int new_y)
{
	if (next_tile == 'C')
	{
		game->score++;
		game->map[new_x][new_y] = '0';
	}
	if (next_tile == 'E' && game->score == game->num_collectibles)
	{
		ft_printf("You Win!\n");
		destroy_images(game);
		destroy_game(game);
		exit(0);
	}
}

int	check_exit_and_wall(char next_tile, t_game *game, int new_x, int new_y)
{
	if (next_tile == '1')
		return (0);
	check_next_tile(next_tile, game, new_x, new_y);
	if (next_tile == 'E')
		return (0);
	return (1);
}

int	press_key(int keycode, t_game *game)
{
	int		old_x;
	int		old_y;
	int		new_x;
	int		new_y;
	char	next_tile;

	old_x = game->player_x;
	old_y = game->player_y;
	new_x = old_x;
	new_y = old_y;
	escape_key(keycode, game);
	new_position(game, &new_x, &new_y, keycode);
	count_moves(keycode);
	next_tile = game->map[new_x][new_y];
	if (!check_exit_and_wall(next_tile, game, new_x, new_y))
		return (0);
	game->map[old_x][old_y] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_x][game->player_y] = 'P';
	redraw_game(game);
	return (0);
}
