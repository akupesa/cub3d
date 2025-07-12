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
# include <sys/time.h>

// File read Buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Engine process() function call interval in seconds
# ifndef AMOUNT_TO_CALL
#  define AMOUNT_TO_CALL 0.25
# endif

// Game Controls
enum e_control {
	ESC = 65307,
	MLX_A = 97,
	MLX_D = 100,
	MLX_S = 115,
	MLX_W = 119,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	JUMP_KEY = 32,
	SHIFT_KEY = 65505
};

// Vector functions
t_vector2d		vec2d_zero(void);
t_vector2d		vec2d_create(double_t x, double_t y);
t_vector2d		vec2d_add(t_vector2d lop, t_vector2d rop);
t_vector2d		vec2d_addby(t_vector2d lop, double_t rop);
t_vector2d		vec2d_sub(t_vector2d lop, t_vector2d rop);
t_vector2d		vec2d_subby(t_vector2d lop, double_t rop);
t_vector2d		vec2d_mult(t_vector2d lop, t_vector2d rop);
t_vector2d		vec2d_multby(t_vector2d lop, double_t rop);
t_vector2d		vec2d_div(t_vector2d lop, t_vector2d rop);
t_vector2d		vec2d_divby(t_vector2d lop, double_t rop);
t_vector2d		vec2d_sqrt(t_vector2d lop);
t_vector2d		vec2d_pow(t_vector2d lop, double_t rop);

// Map reading
void			load_map(t_cub *cub, const char *file_name);
void			get_file(t_cub *cub, const char *file_name);

// Map validation
void			map_validator(t_cub *cub);
void			is_map_empty(t_cub *cub, int i);
bool			chars_validator(char c);
bool			player_validator(t_cub *cub);
bool			is_there_two_n(t_cub *cub, int i);
bool			map_not_closed(t_cub *cub, const char **matrix);

// Utils
char			*ft_strjoint(char *s1, char *s2);
unsigned int	get_image_pixel(const t_cub *cub, const t_img *img,
					const t_coords pos);
unsigned int	get_texture_pixel(const t_texture *text, const t_coords pos);
int				get_texture_x(const t_dda_result result,
					const t_texture *texture);
void			verify_path(t_cub *cub);
void			dda_clamp(t_dda_data *dda, const t_vector2d pos,
					const t_vector2d dir);
void			put_texture_pixel(t_texture *text, const t_coords pos,
					const unsigned int color);
void			put_image_pixel(const t_cub *cub, const t_img *img,
					const t_coords pos, const unsigned int color);
t_coords		get_coords(t_cub *cub);
t_dda_data		iterate_to_wall(t_cub *cub, t_dda_data dda);
t_texture		*get_wall_texture(t_cub *cub, const t_dda_result result);

// Main loop
int				cub_loop(t_cub *cub);

// Controls
int				control_cub(int keycode, t_cub *cub);
int				control_release_cub(int keycode, t_cub *cub);

// Physics
void			physics_cub(t_cub *cub);

// Process
void			process_cub(t_cub *cub);

// Render & Ray
void			render_ray(t_cub *cub);
void			render_cub(t_cub *cub);
void			render_skybox(t_cub *cub);
void			init_raycasting(t_cub *cub);

// Allocation and liberation
int				free_all(t_cub *cub, int fd);
void			free_and_print(t_cub *cub, char *str, int fd);

#endif
