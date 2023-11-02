/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:13:21 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/20 11:21:00 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1' && game->img_wall)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_wall, game->x_pos, game->y_pos);
	if (game->map[i][j] == 'C' && game->img_collect)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_collect, game->x_pos, game->y_pos);
	if (game->map[i][j] == 'E' && game->img_exit)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_exit, game->x_pos, game->y_pos);
}

void	draw_player(t_game *game)
{
	int	player_x_pos;
	int	player_y_pos;

	player_x_pos = game->player_y * IMG_SIZE;
	player_y_pos = game->player_x * IMG_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_player, player_x_pos, player_y_pos);
}

void	redraw_game(t_game *game)
{
	int	i;
	int	j;

	if (!game || !game->map)
		return ;
	mlx_clear_window(game->mlx, game->mlx_win);
	i = 0;
	draw_player(game);
	while (i < game->num_lines)
	{
		j = 0;
		while (j < game->len)
		{
			game->x_pos = j * IMG_SIZE;
			game->y_pos = i * IMG_SIZE;
			draw_images(game, i, j);
			j++;
		}
		i++;
	}
}
