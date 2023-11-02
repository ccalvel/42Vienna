/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:30:15 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/20 12:07:38 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_game *game)
{
	int	size_wx;
	int	size_wy;

	size_wx = 32 * game->len;
	size_wy = 32 * game->num_lines;
	game->mlx_win = mlx_new_window(game->mlx, size_wx, size_wy, "so_long");
}

void	escape_key(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		destroy_images(game);
		destroy_game(game);
		exit(1);
	}
}

void	cleanup_window(t_game *game)
{
	if (game->mlx_win != NULL)
	{
		free_player_pos(game);
		destroy_images(game);
		destroy_game(game);
		exit(1);
	}
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup_window(game);
	return (0);
}
