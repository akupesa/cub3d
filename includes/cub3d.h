/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:10:29 by akupesa           #+#    #+#             */
/*   Updated: 2025/05/29 12:38:00 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# include "../minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/time.h>

// File read Buffer
# define BUFFER_SIZE 42

// Engine process() function call amount inside a second
# define AMOUNT_TO_CALL 0.2

// Window frame size
# define WIDTH 1280
# define HEIGHT 720

// Engine Controls
# define ESC 65307

// Game Controls
# define MLX_A 97
# define MLX_D 100
# define MLX_S 115
# define MLX_W 119
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363

// Vector functions
t_vector2d	vec2d_create(double_t x, double_t y);
t_vector2d	vec2d_zero(void);
t_vector2d	vec2d_add(t_vector2d lop, t_vector2d rop);
t_vector2d	vec2d_addby(t_vector2d lop, double_t rop);
t_vector2d	vec2d_sub(t_vector2d lop, t_vector2d rop);
t_vector2d	vec2d_subby(t_vector2d lop, double_t rop);
t_vector2d	vec2d_mult(t_vector2d lop, t_vector2d rop);
t_vector2d	vec2d_multby(t_vector2d lop, double_t rop);
t_vector2d	vec2d_div(t_vector2d lop, t_vector2d rop);
t_vector2d	vec2d_divby(t_vector2d lop, double_t rop);
t_vector2d	vec2d_pow(t_vector2d lop, double_t rop);
t_vector2d	vec2d_sqrt(t_vector2d lop);

// Map reading
void		load_map(t_cub *cub, const char *file_name);
void		get_file(t_cub *cub, const char *file_name);

// Map validation
void		is_map_empty(t_cub *cub, int i);
void		map_validator(t_cub *cub);
bool		player_validator(t_cub *cub);
bool		chars_validator(char c);
bool		is_there_two_n(t_cub *cub, int i);
bool		map_not_closed(t_cub *cub);

// Utils
char		*ft_strjoint(char *s1, char *s2);
t_coords	get_coords(t_cub *cub);

// Main loop
int			cub_loop(t_cub *cub);

// Controls
int			control_cub(int keycode, t_cub *cub);

// Physics
void		physics_cub(t_cub *cub);

// Process
void		process_cub(t_cub *cub);

// Physics & Process Applycation
void		physics_process_cub(t_cub *cub);

// Render
void		render_cub(t_cub *cub);
void		render_background(t_cub *cub);

// Allocation and liberation
int			free_all(t_cub *cub, int fd);
void		free_and_print(t_cub *cub, char *str, int fd);

#endif
