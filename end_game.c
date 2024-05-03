/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:51:41 by machouba          #+#    #+#             */
/*   Updated: 2024/05/03 13:59:36 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	while (game->plot.height > 0)
	{
		free(game->plot.map[game->plot.height - 1]);
		game->plot.height++;
	}
	free(game->plot.map);
	return ;
}

int	check_env(char **envp)
{
	const char	*env;
	char		*val_va;
	int			i;

	env = "USER";
	val_va = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	end_game(char *message, t_game *game, enum e_state i)
{
	if (i == env_error || i == error || i == file_error)
	{
		ft_printf("Error\n%s\n", message);
		exit(1);
	}
}
