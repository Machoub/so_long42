#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/src/libft.h"
#include "libft/src/ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

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

typedef struct s_game
{
    void    *mlx_ptr;
    void    *windows_ptr;
    t_draw  plot;
}               t_game;

typedef struct s_draw
{
    char    *line;
    char    **map;
    int     height;
    int     lenght;
}               t_draw;


enum    e_state
{
    error = 2,
    file_error = 3,
    env_error = 7,

};

void    end_game(char *message, t_game *game, enum e_state i);
int check_env(char **envp);
void    init_map(t_game *game, char *path);

# endif