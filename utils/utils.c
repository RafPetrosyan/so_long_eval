/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:14:46 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 18:15:22 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_size(char *path)
{
	int		fd;
	int		map_size;
	char	*line;

	fd = open(path, O_RDONLY);
	map_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_size == 0)
			{
				close(fd);
				exit(printf("Error\nMap is empty\n"));
			}
			break ;
		}
		else
			map_size++;
		free(line);
	}
	close(fd);
	return (map_size);
}

t_map	get_dimensions(char **str)
{
	int		i;
	int		len;
	t_map	map;

	i = 0;
	map.cols = 0;
	map.rows = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (len != 0)
		{
			if (len > map.cols)
				map.cols = len;
			map.rows++;
		}
		i++;
	}
	return (map);
}

char	**trim_map(t_game *game, int size)
{
	int		i;
	int		j;
	int		k;
	t_map	map;

	map = get_dimensions(game->map);
	i = get_i_pos(game, size);
	j = get_j_pos(game, size);
	k = 0;
	if (map.rows > j - i)
		ft_exit("Error\nMap has empty lines\n", game);
	game->trim = malloc((j - i + 1) * sizeof(char *));
	if (!game->trim)
		return (NULL);
	while (i < j)
	{
		game->trim[k] = malloc(ft_strlen(game->map[i]) + 1);
		ft_strlcpy(game->trim[k], game->map[i], ft_strlen(game->map[i]) + 1);
		i++;
		k++;
	}
	free_map(game->map);
	game->trim[k] = NULL;
	return (game->trim);
}

char	**read_map(char *path)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	t_game	game;

	i = 0;
	size = get_size(path);
	fd = open(path, O_RDONLY);
	game.map = (char **)malloc((size + 1) * sizeof(char *));
	if (game.map == 0)
		return (NULL);
	while (i < size)
	{
		line = get_next_line(fd);
		game.t_line = ft_strtrim(line, "\n\t ");
		game.map[i] = malloc(ft_strlen(game.t_line) + 1);
		ft_strlcpy(game.map[i], game.t_line, ft_strlen(game.t_line) + 1);
		free(line);
		free(game.t_line);
		++i;
	}
	game.map[i] = NULL;
	game.map = trim_map(&game, size);
	return (game.map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
