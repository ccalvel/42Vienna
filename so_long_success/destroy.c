/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:07:02 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/20 11:07:03 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->player_pos)
		free_player_pos(game);
	if (game->map)
		free_map(game);
	free(game);
	game = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

void	free_player_pos(t_game *game)
{
	int	i;

	if (!game->player_pos)
		return ;
	i = 0;
	while (i < game->num_lines && game->player_pos[i])
	{
		free(game->player_pos[i]);
		i++;
	}
	free(game->player_pos);
	game->player_pos = NULL;
}

void	destroy_images(t_game *game)
{
	if (game->img_wall != NULL)
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = NULL;
	}
	if (game->img_player != NULL)
	{
		mlx_destroy_image(game->mlx, game->img_player);
		game->img_player = NULL;
	}
	if (game->img_collect != NULL)
	{
		mlx_destroy_image(game->mlx, game->img_collect);
		game->img_collect = NULL;
	}
	if (game->img_exit != NULL)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = NULL;
	}
}
