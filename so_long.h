/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:21 by machouba          #+#    #+#             */
/*   Updated: 2024/05/05 18:11:00 by machouba         ###   ########.fr       */
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

# define KEY_PRESS 02
# define DESTROY_NOTIF 17
# define EXPOSE 12

# define KEY_PRESS_MASK 1
# define EXPOSURE_MASK 32768
# define NO_EVENT_MASK 0

# define WALL "./img_xpm/wall.xpm"
# define FLOOR "./img_xpm/floor.xpm"
# define ITEM "./img_xpm/item.xpm"
# define DJ_OPEN "./img_xpm/dj_open.xpm"
# define DJ_CLOSE "./img_xpm/dj_close.xpm"
# define PLAYER "./img_xpm/player.xpm"
# define PLAYER_LEFT "./img_xpm/player_left.xpm"
# define PLAYER_RIGHT "./img_xpm/player_right.xpm"
# define PLAYER_UP "./img_xpm/player_up.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_img
{
	void	*ptr;
	int		*pxl;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		mouv;
}			t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*windows_ptr;
	t_skins		i;
	t_draw		plot;
	t_img		player;
	t_img		player_left;
	t_img		player_right;
	t_img		player_upper;
	t_img		floor;
	t_img		wall;
	t_img		item;
	t_img		dj_open;
	t_img		dj_close;
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
	event_end = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
	design_map_error = 5,
	img_error = 6,
	env_error = 7,
};

enum	e_dir
{
	up,
	down,
	left,
	right,
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
void	init_window(t_game *game);
bool	not_window(t_game *game);
t_point	get_screen_size(t_game *game);
int		red_cross(t_game *game);
void	init_img_nul(t_game *game);

#endif