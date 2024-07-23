/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validacia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:32:21 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 17:57:18 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		++i;
	if (!(str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r'
			&& str[i + 4] == '\0'))
		ft_exit("Error\nInvalid format\n", NULL);
}

void	check_chars(t_game *game, char c)
{
	if (c == 'E')
		game->player.exit_count++;
	else if (c == 'P')
		game->player.player_count++;
	else if (c == 'C')
		game->player.collectible_count++;
	else if (c == '1' || c == '0')
		return ;
	else
		ft_exit("Error\nInvalid characters\n", game);
}

void	validate_map(char *path)
{
	int		i;
	int		j;
	t_game	game;

	game.player.collectible_count = 0;
	game.player.exit_count = 0;
	game.player.forbidden_chars = 0;
	game.player.player_count = 0;
	i = 0;
	game.map = read_map(path);
	if (!game.map)
		exit(2);
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			check_chars(&game, game.map[i][j]);
			j++;
		}
		i++;
	}
	handle_error_messages(&game, path);
	free_map(game.map);
}

void	validation(int argc, char **argv)
{
	t_game	game;
	t_map	dimensions;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		dimensions = get_dimensions(game.map);
		game.map_height = dimensions.rows;
		game.map_width = dimensions.cols;
		check_format(argv[1]);
		validate_map(argv[1]);
		if (!validate_path(&game, argv[1]))
			ft_exit("Error\nPath is not valid\n", &game);
		else if (!surrounded_walls(game.map))
			ft_exit("Error\nMap isn't surrounded by walls\n", &game);
		free_map(game.map);
	}
	else
		ft_exit("Error\nInvalid number of arguments\n", NULL);
}
