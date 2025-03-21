/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:10:29 by akupesa           #+#    #+#             */
/*   Updated: 2025/02/26 15:49:14 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <time.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>

# include "cub3d_struct.h"
# include "../minilibx-linux/mlx.h"

# define BUFFER_SIZE 42
# define TABLE_SIZE 53

# define WIDTH 1280
# define HEIGHT 720

# define ESC 65307

# define MLX_A 97
# define MLX_D 100
# define MLX_S 115
# define MLX_W 119
// # define UP_KEY 65362
# define LEFT_KEY 65361
// # define DOWN_KEY 65364
# define RIGHT_KEY 65363

int		free_all(t_cub *cub, int fd);
int		is_there_two_n(t_cub *cub);
bool		player_validator(t_cub *cub);
int		keys_handler(int keycode, t_cub *cub);
int		map_validator(t_cub *cub);
int		load_map(t_cub *cub, const char *file_name);

char		**map_copy(t_cub *cub);
char		*get_next_line(int fd);
bool		chars_validator(char c);

void		hook(t_cub *cub);
void		destroy_items(t_cub *cub);
void		simple_free(t_cub *cub, char *str, int fd);
void		is_map_empty(t_cub *cub, int fd, char *fullmap);

t_coords	get_coords(t_cub *cub);


#endif
