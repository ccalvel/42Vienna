/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:24:45 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:46:42 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check(t_game *game)
{
	free_map(game);
	if (game)
		free(game);
	exit(1);
}

void	check_walls(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (game->map[0])
		game->len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x] && x <= game->len - 1)
		{
			if (i == 0 || x == 0 || x == game->len - 1
				|| i == game->num_lines - 1)
			{
				if (game->map[i][x] != '1')
				{
					ft_printf("Error\nWall not valid \n");
					free_check(game);
				}
			}
			x++;
		}
		i++;
	}
}

void	check_rect(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (game->map[0])
	{
		game->len = ft_strlen(game->map[0]);
	}
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (game->len != len)
		{
			write(2, "Error\n", 6);
			ft_printf("No rectangle\n");
			free_check(game);
		}
		i++;
	}
}

void	check_letters(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] != '0' && game->map[i][x] != '1'
				&& game->map[i][x] != 'C' && game->map[i][x] != 'E'
				&& game->map[i][x] != 'P' && game->map[i][x] != '\n')
			{
				write(2, "Error\n", 6);
				ft_printf("Incorrect letter in map\n");
				free_check(game);
				exit(1);
			}
			x++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	check_letters(game);
	check_walls(game);
	check_rect(game);
}
