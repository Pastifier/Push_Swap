/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/08 22:45:00 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_stack	a;
	static t_stack	b;
	int				*sorted_arr;

	if (argc < 2)
		return (0);
	check_empty(--argc, ++argv);
	validate_input(&a, argc, argv);
	if (!issorted(&a))
	{
		sorted_arr = cpy_stack_to_array_sort(&a);
		if (!sorted_arr)
			return (free_elements(&a), submit_error(), 2);
		if (a.capacity == 2)
			sort_two(&a, A);
		else if (a.capacity == 3)
			sort_three(&a);
		else
			(radix_sort(&a, &b, sorted_arr), free(sorted_arr));
	}
	return (free_elements(&a), 0);
}
