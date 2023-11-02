/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_how_much.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:08:15 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:01:05 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_how_many_exit(t_game *game)
{
	int	i;
	int	x;
	int	count_e;

	i = 0;
	count_e = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'E')
				count_e ++;
			x++;
		}
		i++;
	}
	if (count_e != 1)
	{
		write(2, "Error\n", 6);
		ft_printf("Invalid Number of exit.\n");
		free_check(game);
		exit(1);
	}
}

void	check_how_many_players(t_game *game)
{
	int	i;
	int	x;
	int	count_p;

	i = 0;
	count_p = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'P')
				count_p ++;
			x++;
		}
		i++;
	}
	if (count_p > 1 || count_p == 0)
	{
		write(2, "Error\n", 6);
		ft_printf("You have %d player.\n");
		free_check(game);
		exit(1);
	}
}

void	check_how_many_collectibles(t_game *game)
{
	int	i;
	int	x;
	int	count_c;

	i = 0;
	count_c = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'C')
				count_c ++;
			x++;
		}
		i++;
	}
	if (count_c == 0)
	{
		write(2, "Error\n", 6);
		ft_printf("You don't have collectibles.\n");
		free_check(game);
		exit(1);
	}
	game->num_collectibles = count_c;
}

void	check_how_much(t_game *game)
{
	check_how_many_exit(game);
	check_how_many_players(game);
	check_how_many_collectibles(game);
}

void	check_collectibles_to_exit(t_game *game)
{
	int	i;
	int	x;
	int	count_c;

	i = 0;
	x = 0;
	count_c = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'C')
				count_c ++;
			x++;
		}
		i++;
	}
}
