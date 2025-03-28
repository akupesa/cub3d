# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupesa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 13:27:06 by akupesa           #+#    #+#              #
#    Updated: 2025/03/06 11:24:34 by gecarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/all_frees.c \
	srcs/flood_fill_validator.c \
	srcs/get_next_line.c \
	srcs/hash.c \
	srcs/hash_motion.c \
	srcs/keys_handlers.c \
	srcs/loop.c \
	srcs/main.c \
	srcs/map.c \
	srcs/map_validator.c \
	srcs/map_items_validator.c \
	srcs/map_reader.c \
	srcs/textures_to_window.c \
	srcs/validator_args.c

OBJ = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDES = -I./includes -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
