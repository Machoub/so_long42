#include "so_long.h"

static void read_map(t_game *game, int fd)
{
    char    *tmp;

    tmp = ft_strdup("");
    game->plot.height = 0;
    while (fd)
    {
        game->plot.line = get_next_line(fd);
        if (game->plot.line == NULL)
            break ;
        tmp = ft_strjoin(tmp, game->plot.line);
        game->plot.height++;
    }
    game->i = start_counter(tmp, game);
    game->plot.map = ft_split(tmp, '\n');
    free(tmp);
    return ;
}

void    init_map(t_game *game, char *path)
{
    int fd;

    fd = open_file(path);
    read_map(game, fd);
    colse(fd);
    return ;
}