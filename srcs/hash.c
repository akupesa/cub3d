/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:55:48 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/20 10:55:51 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int    ft_hash(const char *key)
{
        unsigned int    hash;

        while (*key)
        {
                hash = (hash * 31) + *key;
                key++;
        }
        return (hash % TABLE_SIZE);
}

t_hashtable     *init_hashtable(void)
{
        int             i;
        t_hashtable     hash;

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
