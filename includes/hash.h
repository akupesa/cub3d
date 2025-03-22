/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:40:03 by akupesa           #+#    #+#             */
/*   Updated: 2025/03/22 10:40:06 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# define TABLE_SIZE 53

typedef struct s_entrance
{
        char                    *key; // "NO", "SO", "WE", "EA"
        void                    *value; // ponteiro genérico para texturas, cores, etc...
        struct s_entrance       *next; //encadeamento para lidar com colisões
}                               t_entrance;

typedef struct s_hashtable
{
        t_entrance      *table[TABLE_SIZE]; //array de listas para armazenar entradas
}                               t_hastable;


#endif
