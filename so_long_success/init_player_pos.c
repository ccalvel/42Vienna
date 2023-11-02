/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:27:27 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:12:20 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_player_pos(t_game *game)
{
	int	i;

	if (game->player_pos != NULL)
		free_player_pos(game);
	game->player_pos = malloc(sizeof(int *) * game->num_lines);
	i = 0;
	while (i < game->num_lines)
	{
		game->player_pos[i] = malloc(sizeof(int) * game->len);
		i++;
	}
	if (game->player_pos == NULL)
	{
		write(2, "Error\n", 6);
		ft_printf("Memory allocation failed\n");
		free_player_pos(game);
		destroy_images(game);
		destroy_game(game);
		exit(1);
	}
}

void	init_coordinates(t_game *game)
{
	if (!game || !game->map)
	{
		write(2, "Error\n", 6);
		ft_printf("Error loading game or map.\n");
		return ;
	}
	game->x = 0;
	game->y = 0;
}

void	init_player_pos(t_game *game)
{
	int	i;
	int	j;

	init_coordinates(game);
	alloc_player_pos(game);
	i = 0;
	while (i < game->num_lines)
	{
		j = 0;
		while (j < game->len)
		{
			if (!game->player_pos || !game->player_pos[i])
			{
				write(2, "Error\n", 6);
				ft_printf("Error with the player position.\n", i);
				return ;
			}
			game->player_pos[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	update_player_coordinates(t_game *game, int i, int j)
{
	if (!game->map[i])
	{
		write(2, "Error\n", 6);
		ft_printf("Null pointer detected for map row.\n");
		return ;
	}
	if (i >= game->num_lines || j >= game->len)
	{
		write(2, "Error\n", 6);
		ft_printf("Out of limits.\n");
		return ;
	}
	if (game->map[i][j] == 'P')
	{
		game->x = i;
		game->y = j;
		game->player_pos[game->x][game->y] = 1;
		game->player_x = game->x;
		game->player_y = game->y;
	}
}

void	update_player_pos(t_game *game)
{
	int	i;
	int	j;

	init_player_pos(game);
	i = 0;
	while (i < game->num_lines)
	{
		j = 0;
		while (j < game->len)
		{
			update_player_coordinates(game, i, j);
			j++;
		}
		i++;
	}
}
