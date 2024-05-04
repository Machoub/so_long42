/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:21 by machouba          #+#    #+#             */
/*   Updated: 2024/05/04 17:57:44 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/get_next_line.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define SPR_SZ 64
# define WINDOW_NAME "./so_long"

# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define SPEED 1

# define KEY_PRESS 02
# define DESTROY_NOTIF 17
# define EXPOSE 12

# define KEY_PRESS_MASK 1
# define EXPOSURE_MASK 32768
# define NO_EVENT_MASK 0

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*windows_ptr;
	t_skins		i;
	t_draw		plot;
}			t_game;

typedef struct s_draw
{
	char	*line;
	char	**map;
	int		height;
	int		lenght;
}			t_draw;

typedef struct s_skins
{
	int	empty;
	int	collect;
	int	exit;
	int	start;
	int	movements;
}			t_skins;

enum	e_state
{
	error = 2,
	file_error = 3,
	map_char_error = 4,
	design_map_error = 5,
	env_error = 7,
};

void	end_game(char *message, t_game *game, enum e_state i);
int		check_env(char **envp);
void	init_map(t_game *game, char *path);
t_skins	init_counter(void);
int		open_file(char *path);
bool	double_line(char *str, int i);
void	is_items_valid(t_game *game, t_skins *items, char *str);
int		len_map(char **map, t_game *game);
void	free_map(t_game *game);
bool	valid_character(t_game *game, int y, int x);
void	parsing_map(t_game *game);
bool	maps_walls(t_game *game, int y, int x);
bool	rectangular(t_game *game, int y, int x);
char	**copy_map(t_game *game, int y, int x);
char	**alloc_map_mem(t_game *game, int y, int x);
int		is_valid_pos(int i, int j, int y, int x);
void	check_path_collect(t_game *game, t_point coord);
void	check_path_player(t_game *game, t_point coord);
void	free_map_test(char **map, int x);

#endif