/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:36:34 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 11:59:53 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	update_state1(t_game *game, int new_x, int new_y)
{
	int	current_row;
	int	current_col;
	int	new_row;
	int	new_col;

	current_row = game->player.y / 32;
	current_col = game->player.x / 32;
	new_row = new_y / 32;
	new_col = new_x / 32;
	if (game->map[new_row][new_col] == 'C')
		game->collected++;
	game->map[current_row][current_col] = '0';
	game->map[new_row][new_col] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	mlx_clear_window(game->mlx, game->mlx_win);
	parse_map(game);
	ft_printf("Moves: %d\n", game->moves++);
}

void	do_move(t_game *game, int new_x, int new_y)
{
	int	move;
	int	x;
	int	y;

	move = 0;
	if (game->player.x != new_x || game->player.y != new_y)
		move = 1;
	x = game->player.x;
	y = game->player.y;
	update_state1(game, new_x, new_y);
	if (game->player.on_exit == 1 && move)
	{
		game->player.on_exit = 0;
		game->map[y / 32][x / 32] = 'E';
		mlx_clear_window(game->mlx, game->mlx_win);
		parse_map(game);
	}
}

void	move(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < game->map_width
		&& new_y >= 0 && new_y < game->map_height
		&& (game->map[new_y / 32][new_x / 32] != '1'))
	{
		if (game->map[new_y / 32][new_x / 32] == 'E')
		{
			if (game->collected != game->collectables)
			{
				do_move(game, new_x, new_y);
				game->player.on_exit = 1;
				return ;
			}
			else if (game->collected == game->collectables)
			{
				ft_printf("You win!!!\n");
				free_map(game->map);
				destroy_textures(game);
				exit(0);
			}
		}
		do_move(game, new_x, new_y);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		move(game, game->player.x, game->player.y - 32);
	else if (keycode == KEY_A)
		move(game, game->player.x - 32, game->player.y);
	else if (keycode == KEY_S)
		move(game, game->player.x, game->player.y + 32);
	else if (keycode == KEY_D)
		move(game, game->player.x + 32, game->player.y);
	return (0);
}

void	init_game(char *path)
{
	t_game	game;
	t_map	map;

	game.map = read_map(path);
	game.x = 0;
	game.y = 0;
	map = get_dimensions(game.map);
	game.map_width = map.cols * 32;
	game.map_height = map.rows * 32;
	game.collectables = get_counts(game.map).collectables;
	game.moves = 1;
	game.player.on_exit = 0;
	game.collected = 0;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map_width,
			game.map_height, "so_long");
	init_textures(&game);
	parse_map(&game);
	mlx_hook(game.mlx_win, 2, 1, key_press, &game);
	mlx_hook(game.mlx_win, 17, 131072, exit_game, &game);
	mlx_loop(game.mlx);
}
