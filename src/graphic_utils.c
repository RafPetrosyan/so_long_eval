/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:11:28 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 17:55:55 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_textures(t_game *game)
{
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	else if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	else if (game->textures.collectable)
		mlx_destroy_image(game->mlx, game->textures.collectable);
	else if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	else if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
}

void	draw(t_game *game, int x, int y, char c)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.floor, x, y);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.collectable, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.player, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->textures.exit, x, y);
}

void	init_textures(t_game *game)
{
	int	len;

	len = 32;
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &len, &len);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &len, &len);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &len, &len);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &len, &len);
	game->textures.collectable = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectable.xpm", &len, &len);
	if (!game->textures.floor || !game->textures.wall || !game->textures.player
		|| !game->textures.exit || !game->textures.collectable)
		ft_exit("Error\nTextures don't found\n", game);
}

void	parse_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->y = 0;
	while (game->map[i])
	{
		game->x = 0;
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = game->x;
				game->player.y = game->y;
				draw(game, game->player.x, game->player.y, 'P');
			}
			else
				draw(game, game->x, game->y, game->map[i][j]);
			game->x += 32;
			j++;
		}
		game->y += 32;
		i++;
	}
}
