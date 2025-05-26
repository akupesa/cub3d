/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:10:29 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:33:56 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# include "../minilibx-linux/mlx.h"

# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>

# define BUFFER_SIZE 42

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

int			map_validator(t_cub *cub);
int			free_all(t_cub *cub, int fd);
int			keys_handler(int keycode, t_cub *cub);
int			load_map(t_cub *cub, const char *file_name);

bool		chars_validator(char c);
bool		player_validator(t_cub *cub);
bool		is_there_two_n(char *fullmap);

char		**map_copy(t_cub *cub);
char		*get_next_line(int fd);

void		hook(t_cub *cub);
void		destroy_items(t_cub *cub);
void		render_background(t_cub *cub);
void		simple_free(t_cub *cub, char *str, int fd);
void		is_map_empty(t_cub *cub, char *fullmap);

t_coords	get_coords(t_cub *cub);

#endif
