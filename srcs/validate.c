/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:54 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:55 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "validate.h"
#include "hash_table.h"
#include <stdlib.h>

static void	check_empty_string(const char *str);

void	submit_error(void)
{
	return ((void)write(2, "Error\n", 6));
}

void	check_empty(int inputc, char *inputv[])
{
	while (inputc--)
		check_empty_string(inputv[inputc]);
}

bool	set_insert(t_entry *set, int value, size_t set_size)
{
	ssize_t	prelim;
	size_t	hash;

	if (!set || !set_size)
		return (false);
	prelim = value % set_size;
	if (prelim < 0)
		prelim *= -1;
	hash = prelim;
	if (set[hash].occupied && set[hash].value == value)
		return (false);
	if (set[hash].occupied)
	{
		while (set[++hash].occupied)
		{
			if (set[hash].value == value)
				return (false);
			if (hash >= set_size)
				hash = 0;
		}
	}
	set[hash].occupied = true;
	set[hash].value = value;
	return (true);
}

bool	is_white(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	check_empty_string(const char *str)
{
	while (is_white(*str))
		++str;
	if (!*str)
		return (submit_error(), exit(EXIT_FAILURE));
}
