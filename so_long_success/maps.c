/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:35:09 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:05:16 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line, t_game *game)
{
	if (!line)
	{
		write(2, "Error\n", 6);
		ft_printf("Error, no lines in file\n");
		destroy_game(game);
		exit(1);
	}
}

int	ft_count_lines(char *argv, t_game *game)
{
	char	*line;
	int		count;
	int		fd_map;

	count = 0;
	fd_map = open(argv, O_RDONLY);
	if (fd_map < 0)
	{
		write(2, "Error\n", 6);
		ft_printf("Error opening file\n");
		destroy_game(game);
		exit(1);
	}
	line = get_next_line(fd_map);
	check_line(line, game);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd_map);
	}
	close(fd_map);
	return (count);
}

void	player_pos(t_game *game, char *line, int count)
{
	int	i;

	game->score = 0;
	game->num_collectibles = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'P')
		{
			game->player_y = count;
			game->player_x = i;
		}
		else if (line[i] == 'E')
		{
			game->exit_y = count;
			game->exit_x = i;
		}
		else if (line[i] == 'C')
		{
			game->num_collectibles++;
		}
		i++;
	}
}

void	read_and_duplicate_lines(t_game *game, int fd_map, int *count)
{
	char	*line;

	line = get_next_line(fd_map);
	while (line != NULL)
	{
		game->map[*count] = ft_strdup(line);
		if (!game->map[*count])
		{
			free(line);
			destroy_game(game);
			exit(1);
		}
		player_pos (game, line, *count);
		free(line);
		(*count)++;
		line = get_next_line(fd_map);
	}
}

void	read_map(char *argv, t_game *game)
{
	int		fd_map;
	int		count;

	game->num_lines = ft_count_lines(argv, game);
	game->map = ft_calloc(sizeof(char *), (game->num_lines + 1));
	if (!game->map)
	{
		destroy_game(game);
		exit(1);
	}
	count = 0;
	fd_map = open(argv, O_RDONLY);
	if (fd_map < 0)
	{
		destroy_game(game);
		exit (1);
	}
	read_and_duplicate_lines(game, fd_map, &count);
	if (count > 0)
		game->len = ft_strlen(game->map[0]);
	game->map[count] = NULL;
	close(fd_map);
}
