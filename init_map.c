/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:38 by machouba          #+#    #+#             */
/*   Updated: 2024/05/03 13:51:44 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_items(t_skins *cnt, char c)
{
	if (c == 'C')
		cnt->collect++;
	else if (c == 'E')
		cnt->exit++;
	else if (c == 'P')
		cnt->start++;
	else if (c == '0')
		cnt->empty++;
}

static void	counter(char *str, t_game *game)
{
	t_skins	items;
	int		i;

	i = 0;
	items = init_counter();
	while (str[i])
	{
		if (double_line(str, i))
		{
			free(str);
			end_game("Invalid file", game, file_error);
		}
		count_items(&items, str[i]);
		i++;
	}
	is_items_valid(game, &items, str);
	return (items);
}

static void	read_map(t_game *game, int fd)
{
	char	*tmp;

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
	game->i = counter(tmp, game);
	game->plot.map = ft_split(tmp, '\n');
	free(tmp);
	return ;
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_map(game, fd);
	game->plot.lenght = len_map(game->plot.map, game);
	colse(fd);
	return ;
}
