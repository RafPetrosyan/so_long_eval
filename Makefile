# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 14:36:41 by emanukya          #+#    #+#              #
#    Updated: 2024/07/22 18:45:40 by rafpetro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SRC_DIR = src
UTIL_DIR = utils
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(SRC_DIR)/graphic_utils.c \
	   $(SRC_DIR)/init_game.c \
	   $(SRC_DIR)/so_long.c \
	   $(SRC_DIR)/validacia.c \
	   $(UTIL_DIR)/ft_memmove.c \
	   $(UTIL_DIR)/ft_memset.c \
	   $(UTIL_DIR)/ft_puthex.c \
	   $(UTIL_DIR)/ft_putnbr.c \
	   $(UTIL_DIR)/ft_printf.c \
	   $(UTIL_DIR)/ft_printf_utils.c \
	   $(UTIL_DIR)/ft_strdup.c \
	   $(UTIL_DIR)/ft_strlcpy.c \
	   $(UTIL_DIR)/ft_strlen.c \
	   $(UTIL_DIR)/get_next_line.c \
	   $(UTIL_DIR)/utils.c \
	   $(UTIL_DIR)/utils1.c \
	   $(UTIL_DIR)/utils2.c \
	   $(UTIL_DIR)/utils3.c \
	   $(UTIL_DIR)/utils4.c \
	   $(UTIL_DIR)/ft_strtrim.c \
	   $(UTIL_DIR)/ft_substr.c \
	   

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) Makefile
	$(CC) $(CFLAGS) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
