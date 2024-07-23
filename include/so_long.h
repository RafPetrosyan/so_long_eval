/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:10:27 by rafpetro          #+#    #+#             */
/*   Updated: 2024/07/22 17:29:29 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdarg.h>

typedef struct s_map
{
	int		rows;
	int		cols;
}			t_map;

typedef struct s_textures
{
	void		*floor;
	void		*wall;
	void		*exit;
	void		*player;
	void		*collectable;
}			t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		forbidden_chars;
	int		on_exit;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		**trim;
	char		*t_line;
	int			map_width;
	int			map_height;
	int			collectables;
	int			collected;
	int			moves;
	int			x;
	int			y;
	t_player	player;
	t_textures	textures;
}			t_game;

/*
** Gnl Functions
*/

char			*ft_strjoin(char *s1, char *s2, int read_size);
int				ft_check(char *str);
void			rearrange(char *str);
void			ft_strjoin_helper(char *s1, char *s2, char *str, int read_size);

/*
** Printf Functions
*/

int				call_specifier(char c, va_list *list);
int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
void			ft_putnbr_helper(int n, int *count);
int				ft_putnbru(unsigned int n);
void			ft_putnbru_helper(unsigned int n, int *count);
int				ft_puthex(unsigned long long p, char spec);
void			ft_puthex_helper(unsigned long long p, char *hex, int *count);

/*
** String Manipulation Functions
*/

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);

/*
** Memory Functions
*/
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

/*
** Character Classification Functions
*/
// int				ft_isalnum(int c);
// int				ft_isalpha(int c);
// int				ft_isdigit(int c);
int				ft_isspace(int c);
int				contains_only_isspace(const char *str);

/*
** I/O Functions
*/
char			*get_next_line(int fd);

/*
** Additional Utility Functions
*/
int				get_size(char *path);

/*
** Game Related Functions
*/
void			validation(int argc, char **argv);
void			handle_error_messages(t_game *game, char *path);
void			check_format(char *path);
int				is_valid_path(t_game *game, int row, int col);
int				collectible_count(t_game *game, int row, int col);
int				validate_path(t_game *game, char *path);
int				surrounded_walls(char **map);
char			**read_map(char *path);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			validate_map(char *path);
void			init_game(char *path);
int				is_rectangular_map(char **map);
int				update_state(t_game *game, char *path);
int				get_i_pos(t_game *game, int size);
int				get_j_pos(t_game *game, int size);
t_map			get_dimensions(char **str);
void			draw(t_game *game, int x, int y, char c);
int				key_press(int keycode, t_game *game);
void			parse_map(t_game *game);
t_game			get_counts(char **str);
char			*ft_strtrim(char const *s1, char const *set);
void			free_map(char **matrix);
char			**trim_map(t_game *game, int size);
void			init_textures(t_game *game);
void			destroy_textures(t_game *game);
int				exit_game(t_game *game);
void			ft_exit(char *str, t_game *game);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen1(char *str);

#endif
