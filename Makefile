# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupesa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 13:27:06 by akupesa           #+#    #+#              #
#    Updated: 2025/05/30 16:47:53 by gecarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/all_frees.c \
	srcs/hooks.c \
	srcs/main.c \
	srcs/textures_to_window.c \
	srcs/validator_args.c \
	srcs/map/map.c \
	srcs/map/map_validator.c \
	srcs/map/map_reader.c \
	srcs/vector/vector_init.c \
	srcs/vector/vector_math.c \
	srcs/vector/vector_math2.c \
	srcs/engine/process.c \
	srcs/engine/physics.c \
	srcs/engine/physics_process.c \
	srcs/engine/render.c

OBJ = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDES = -I./includes/cub3d.h -I./includes/cub3d_struct.h -I$(LIBFT_DIR)/libft.h -I$(MINILIBX_DIR)/mlx.h
INCLUDES_FILES = ./includes/cub3d.h ./includes/cub3d_struct.h $(LIBFT_DIR)/libft.h $(MINILIBX_DIR)/mlx.h
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(INCLUDES_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
