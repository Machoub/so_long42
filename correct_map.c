/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:01 by machouba          #+#    #+#             */
/*   Updated: 2024/05/03 13:16:42 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_items_valid(t_game *game, t_skins *items, char *str)
{
	if (!(items->collect > 0 && items->exit == 1 && items->start == 1
			&& items->empty > 0))
	{
		free(str);
		end_game("Invalide items", game, file_error);
	}
}

bool	double_line(char *str, int i)
{
	return ((str[i] == '\n') && (ft_strchr("\n\0", str[i + 1])));
}
