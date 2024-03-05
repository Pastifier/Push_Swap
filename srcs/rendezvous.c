/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendezvous.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:48:12 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/05 19:12:30 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	create_map(int *sorted_arr, size_t troop_count, size_t unit_weakness)
{
	return ((t_arr)
		{
			.arr = sorted_arr,
			.chunk_size = troop_count,
			.chunk_pivot = unit_weakness
		}
	);
}

t_arr	edit_map(t_arr map)
{
	map.chunk_pivot += (2 * map.chunk_size / 3);
	map.chunk_size /= 3;
	return (map);
}
