/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:01:13 by machouba          #+#    #+#             */
/*   Updated: 2024/05/06 12:22:10 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
		game->player.ptr, game->player.x, game->player.y);
}

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->dj_open.x = x * SPR_SZ;
		game->dj_open.y = y * SPR_SZ;
		if (game->i.collect == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
				game->dj_open.ptr, (x * SPR_SZ), (y * SPR_SZ));
		else
			mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
				game->dj_close.ptr, (x * SPR_SZ), (y * SPR_SZ));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
			game->wall.ptr, (x * SPR_SZ), (y * SPR_SZ));
	else if (game->plot.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
			game->item.ptr, (x * SPR_SZ), (y * SPR_SZ));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->windows_ptr,
			game->floor.ptr, (x * SPR_SZ), (y * SPR_SZ));
}

void	render_map(t_game *game)
{
	t_point	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			check_map_maker(game, point.y, point.x);
			point.x++;
		}
		point.y++;
	}
	return ;
}
