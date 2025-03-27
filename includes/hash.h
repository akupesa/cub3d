/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:40:03 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:34:02 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <math.h>

# define FLOOR 0
# define WALL 1
# define PLAYER 2
# define ENEMY 3
# define DOOR 4
# define OBSTACLE 5

# define TABLE_SIZE 51

typedef struct s_quad
{
	float_t				x;
	float_t				y;
	float_t				width;
	float_t				height;
}						t_quad;

typedef struct s_entrance
{
	void				*value;
	int					data_type;
	int					hash_value;
	struct s_entrance	*next;
}						t_entrance;

typedef struct s_hashtable
{
	t_entrance			**table;
}						t_hashtable;

#endif
