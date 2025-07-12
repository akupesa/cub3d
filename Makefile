# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupesa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 13:27:06 by akupesa           #+#    #+#              #
#    Updated: 2025/06/18 09:20:40 by gecarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	srcs/all_frees.c \
	srcs/hooks.c \
	srcs/main.c \
	srcs/textures_to_window.c \
	srcs/flood_fill_validator.c \
	srcs/designer/designer.c \
	srcs/designer/designer_utils.c \
	srcs/map/map.c \
	srcs/map/map_validator.c \
	srcs/map/map_reader.c \
	srcs/vector/vector_init.c \
	srcs/vector/vector_math.c \
	srcs/vector/vector_math2.c \
	srcs/engine/process.c \
	srcs/engine/physics.c \
	srcs/engine/render.c

OBJ = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDE_PATH = ./includes/
INCLUDES = -I$(INCLUDE_PATH) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
INCLUDES_FILES = $(INCLUDE_PATH)cub3d.h $(INCLUDE_PATH)cub3d_struct.h $(LIBFT_DIR)/libft.h $(MINILIBX_DIR)/mlx.h
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
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
