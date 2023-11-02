/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:29:03 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:41:41 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_wall(t_game *game)
{
	if (game->img_wall == NULL)
	{
		game->img_wall = mlx_xpm_file_to_image(game->mlx,
				"wall.xpm", &game->img_width, &game->img_height);
		if (game->img_wall == NULL)
		{
			ft_printf("Error \nError loading wall image.\n");
			destroy_images(game);
			destroy_game(game);
			exit(1);
		}
	}
}

void	init_collectibles(t_game *game)
{
	if (game->img_collect == NULL)
	{
		game->img_collect = mlx_xpm_file_to_image(game->mlx,
				"collectible.xpm", &game->img_width, &game->img_height);
		if (game->img_collect == NULL)
		{
			ft_printf("Error \nError loading collectible image.\n");
			destroy_images(game);
			destroy_game(game);
			exit(1);
		}
	}
}

void	init_exit(t_game *game)
{
	if (game->img_exit == NULL)
	{
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"exit.xpm", &game->img_width, &game->img_height);
		if (game->img_exit == NULL)
		{
			write(2, "Error\n", 6);
			ft_printf("Error loading exit image.\n");
			destroy_images(game);
			destroy_game(game);
			exit(1);
		}
	}
}

void	init_player(t_game *game)
{
	if (game->img_player == NULL)
	{
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"monster.xpm", &game->img_width, &game->img_height);
		if (game->img_player == NULL)
		{
			write(2, "Error\n", 6);
			ft_printf("Error loading player image.\n");
			destroy_images(game);
			destroy_game(game);
			exit(1);
		}
	}
}

void	init_images(t_game *game)
{
	init_wall(game);
	init_collectibles(game);
	init_exit(game);
	init_player(game);
}
