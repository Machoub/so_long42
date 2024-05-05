#include "so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->player.mem = 0;
	if (keycode == ESC)
		end_game("", game, event_end);
	else if (keycode == UP)
		move_up(game);
	else if (keycode == DOWN)
		move_down(game);
	else if (keycode == RIGHT)
		move_right(game);
	else if (keycode == LEFT)
		move_left(game);
	return (0);
}

