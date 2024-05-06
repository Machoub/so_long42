/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:26 by machouba          #+#    #+#             */
/*   Updated: 2024/05/06 17:52:11 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game2(char *msg, t_game *game)
{
	ft_printf("Error\n%s\n", msg);
	destroy_img(game);
	return ;
}

static void	line_valid(char **map, t_game *game)
{
	t_point	point;
	int		i;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i])
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			end_game("Error : line note valid", game, error);
		}
		i++;
	}
}

int	len_map(char **map, t_game *game)
{
	line_valid(map, game);
	return (ft_strlen(map[0]));
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error fd\n");
		exit(1);
	}
	return (fd);
}

t_skin	init_counter(void)
{
	t_skin	counter;

	counter.empty = 0;
	counter.collect = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.start = 0;
	return (counter);
}
