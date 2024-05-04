#include "so_long.h"

void	free_map_test(char **map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_path_player(t_game *game, t_point coord)
{
	int				j;
	int				i;
	char	**cpy_map;

	i = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'P')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_player(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("Invalid path palyer -> collect -> exit", game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			j++;
		}
		i++;
	}
}

void	check_path_collect(t_game *game, t_point coord)
{
	int				j;
	int				i;
	char	**cpy_map;

	i = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'C')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_collect(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("Invalid path palyer -> collect -> exit", game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			j++;
		}
		i++;
	}
}