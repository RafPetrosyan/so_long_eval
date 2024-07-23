/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:28:09 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/21 19:09:34 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit(char *str, t_game *game)
{
	ft_printf("Error\nWe've encountered some issues\n%s", str);
	if (game != NULL && game->map[0])
		free_map(game->map);
	exit(1);
}

void	handle_error_messages(t_game *game, char *path)
{
	if (get_size(path) == -1)
		ft_exit("Error\nMap is empty\n", game);
	else if (game->player.exit_count == 0)
		ft_exit("Error\nNo exit was found\n", game);
	else if (game->player.exit_count > 1)
		ft_exit("Error\nMore than one exit\n", game);
	else if (game->player.player_count == 0)
		ft_exit("Error\nNo player was found\n", game);
	else if (game->player.player_count > 1)
		ft_exit("Error\nMore than one player\n", game);
	else if (game->player.collectible_count == 0)
		ft_exit("Error\nNo collectibles was found\n", game);
	else if (!is_rectangular_map(game->map))
		ft_exit("Error\nMap shape is not rectangular\n", game);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	destroy_textures(game);
	ft_printf("Game was closed successfully!\n");
	exit(0);
}

int	is_valid_path(t_game *game, int row, int col)
{
	if (row < 0 || col < 0
		|| row >= game->map_height
		|| col >= game->map_width
		|| game->map[row][col] == '1'
		|| game->map[row][col] == 'v')
		return (0);
	if (game->map[row][col] == 'E')
		return (1);
	game->map[row][col] = 'v';
	return (is_valid_path(game, row + 1, col)
		|| is_valid_path(game, row - 1, col)
		|| is_valid_path(game, row, col + 1)
		|| is_valid_path(game, row, col - 1));
}

int	collectible_count(t_game *game, int row, int col)
{
	int	count;

	count = 0;
	if (row < 0 || col < 0
		|| row >= game->map_height
		|| col >= game->map_width
		|| game->map[row][col] == '1'
		|| game->map[row][col] == 'v')
		return (0);
	if (game->map[row][col] == 'C')
		count++;
	game->map[row][col] = 'v';
	count += collectible_count(game, row + 1, col);
	count += collectible_count(game, row - 1, col);
	count += collectible_count(game, row, col + 1);
	count += collectible_count(game, row, col - 1);
	return (count);
}
