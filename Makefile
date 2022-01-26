# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:40:27 by gjacinta          #+#    #+#              #
#    Updated: 2022/01/26 19:29:48 by gjacinta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c\
	init.c\
	ft_mapcheck.c\
	ft_readmap.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_map_create.c\
	ft_move.c\
	norm.c

HDRS = so_long.h


OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ_BONUS) -I. -o $(NAME)

clean:
		make clean -C mlx
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean