/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:51:37 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/29 12:00:06 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_struct.h"
#include "../includes/hash.h"

void    move_player(t_hashtable *hashtable, t_coords *coords,
		float dx, float dy)
{
	unsigned int	old_index;
	unsigned int	new_index;
	t_coords	*vector;
	t_entrance	*entry;

	vector.x = coords->x + dx;
	vector.y = coords->y + dy;
	old_index = hash_position(coords->x, coords->y, hashtable->size);
	new_index = hash_position(vector.x, vector.y, hashtable->size);
	entry = hashtable->table[new_index];
	while (entry)
	{
		if (entry->data_type == '1')
			return ;
		entry = entry->next;
	}
	remove_from_hashtable(hashtable, coords->x, coords->y);
	// add_to_hashtable(hashtable, '2', &vector);
	coords->x = vector.x;
	coords->y = vector.y;
}
