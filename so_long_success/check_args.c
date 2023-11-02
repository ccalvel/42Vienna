/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:50:55 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/21 14:53:08 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char **argv, t_game *game)
{
	int	len;

	if (argc > 2)
	{
		write(2, "Error\n", 6);
		ft_printf("Error, too much arguments\n");
		destroy_game(game);
		exit(1);
	}
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		ft_printf("There is no map\n");
		destroy_game(game);
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
	{
		write(2, "Error\n", 6);
		ft_printf("Error, no valid format\n");
		destroy_game(game);
		exit(1);
	}
}
