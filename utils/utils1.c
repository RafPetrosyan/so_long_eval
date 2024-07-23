/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:19:02 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 11:22:53 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_i_pos(t_game *game, int size)
{
	int	i;

	i = 0;
	while (i < size && contains_only_isspace(game->map[i]))
		i++;
	return (i);
}

int	get_j_pos(t_game *game, int size)
{
	int	j;

	j = get_i_pos(game, size);
	while (j < size && !contains_only_isspace(game->map[j]))
		j++;
	return (j);
}

t_game	get_counts(char **str)
{
	int		i;
	int		j;
	t_game	game;

	i = 0;
	game.collectables = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				game.collectables++;
			j++;
		}
		i++;
	}
	return (game);
}

int	contains_only_isspace(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_path(t_game *game, char *path)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	game->player.collectible_count = get_counts(game->map).collectables;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	count = update_state(game, path);
	return (is_valid_path(game, game->player.x, game->player.y)
		&& (count == game->player.collectible_count));
}
