/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecarval <gecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:55:48 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/24 09:44:09 by gecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_hashtable	*init_hashtable(void)
{
	int			i;
	t_hashtable	hashtable;

	hash = malloc(sizeof(t_hashtable));
	if (hash == NULL)
		return (NULL);
	i = 0;
	while (i < TABLE_SIZE)
	{
		hash->table[i];
		i++;
	}
	return (hash);
}

unsigned int	ft_hash(const char *key)
{
	unsigned int	hash;

	while (*key)
	{
		hash = (hash * 31) + *key;
		key++;
	}
	return (hash % TABLE_SIZE);
}

unsigned int    hash_position(float x, float y, int table_size)
{
        int     ix;
        int     iy;

        ix = (int)(x * 1000);
        iy = (int)(y * 1000);
        return ((ix * 73856093) ^ (iy * 19349663)) % table_size;
}

void    remove_from_hashtable(t_hashtable *hashtable, int x, int y)
{
        unsigned int    index;
        t_entrance      *entry;
        t_entrance      *prev;

        index = hash_position(x, y, hashtable->size);
        entry = hashtable->table[index];
        prev = NULL;

        while (entry)
        {
                if (entry->data_type == PLAYER)
                {
                        if (prev)
                                prev->next = entry->next;
                        else
                                hashtable->table[index] = entry->next;
                        free(entry);
                        return ;
                }
                prev = entry;
                entry = entry->next;
        }
}

