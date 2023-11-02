/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:25:46 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 13:24:15 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**create_visited_matrix(int width, int height)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			j = 0;
			while (j < i)
			{
				free(visited[j]);
				j++;
			}
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

void	free_visited_matrix(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	ft_floodfill(t_game *game, int x, int y, int *count_c)
{
	if (x <= 0 || x >= game->len || y <= 0 || y >= game->num_lines
		|| game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
	{
		if (game->map[y][x] == 'E')
			game->exitflag = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		(*count_c)--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	ft_floodfill(game, x, (y + 1), count_c);
	ft_floodfill(game, x, (y - 1), count_c);
	ft_floodfill(game, (x + 1), y, count_c);
	ft_floodfill(game, (x - 1), y, count_c);
}

static void	ft_revertback(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->num_lines)
	{
		x = 0;
		while (x < game->len)
		{
			if (game->map[y][x] == 'c')
				game->map[y][x] = 'C';
			else if (game->map[y][x] == 'e')
				game->map[y][x] = 'E';
			else if (game->map[y][x] == 'o')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	validate_game_map(t_game *game)
{
	int	count_c;
	int	**visited;

	game->exitflag = 0;
	count_c = game->num_collectibles;
	visited = create_visited_matrix(game->len, game->num_lines);
	if (!visited)
	{
		return ;
	}
	ft_floodfill(game, game->player_x, game->player_y, &count_c);
	if (count_c != 0)
		ft_printf("Error\n Coin not accessable\n");
	ft_revertback(game);
	if (game->exitflag == 0)
		ft_printf("Error\n Exit not accessable\n");
	free_visited_matrix(visited, game->num_lines);
	if (game->exitflag && count_c == 0)
		game->is_valid_map = 1;
	else
	{
		ft_printf("The map is not valid.\n");
		game->is_valid_map = 0;
	}
}
