/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaldero <ccaldero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:08:27 by ccaldero          #+#    #+#             */
/*   Updated: 2023/09/28 14:56:04 by ccaldero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <string.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define ESC 65307
# define IMG_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		is_valid_map;
	int		len;
	int		num_lines;
	int		x;
	int		y;
	int		**player_pos;
	int		player_x;
	int		player_y;
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	int		img_width;
	int		img_height;
	int		score;
	int		num_collectibles;
	int		line_length;
	int		reached_exit;
	char	**map_copy;
	int		exitflag;
	int		exit_x;
	int		exit_y;
	int		x_pos;
	int		y_pos;
}	t_game;

void	init_images(t_game *game);
int		**malloc_cell(int width, int height);
void	free_cell_status(int **cell_status, int height);
void	free_2d_array(char **array, int rows);
void	check_arg(int argc, char **argv, t_game *game);
int		press_key(int keycode, t_game *game);
char	**copy_map(char **original_map, int num_lines);
char	*get_next_line(int fd);
void	read_map(char *argv, t_game *game);
void	destroy_game(t_game *game);
void	check_map(t_game *game);
void	free_check(t_game *game);
void	check_map(t_game *game);
void	check_collectibles_to_exit(t_game *game);
void	check_how_much(t_game *game);
void	open_window(t_game *game);
void	update_player_pos(t_game *game);
int		loop_iteration(t_game *game);
void	free_map(t_game *game);
void	destroy_images(t_game *game);
void	escape_key(int keycode, t_game *game);
void	cleanup_mlx_init(t_game *game);
//void	cleanup_window(t_game *game);
int		close_window(void *param);
void	redraw_game(t_game *game);
void	free_player_pos(t_game *game);
void	validate_game_map(t_game *game);
//void	validate_game_map(t_game *game, t_flood *flood);

#endif
