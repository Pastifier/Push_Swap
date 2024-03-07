/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:18:37 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/27 05:57:24 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *arr, size_t p, size_t q, size_t r);

void	merge_sort(int *arr, size_t p, size_t r)
{
	size_t	q;

	if (p >= r || (r - p) == 0)
		return ;
	q = (p + r) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge(arr, p, q, r);
}

void	merge(int *arr, size_t start, size_t middle, size_t end)
{
	size_t	p;
	size_t	q;
	size_t	i;
	int		*temp;

	i = 0;
	p = start;
	q = middle + 1;
	temp = malloc(sizeof(int) * (end - start + 1));
	while (p <= middle && q <= end)
	{
		if (arr[p] < arr[q])
			temp[i++] = arr[p++];
		else
			temp[i++] = arr[q++];
	}
	while (p <= middle)
		temp[i++] = arr[p++];
	while (q <= end)
		temp[i++] = arr[q++];
	p = start;
	i = 0;
	while (p <= end)
		arr[p++] = temp[i++];
	free(temp);
}
