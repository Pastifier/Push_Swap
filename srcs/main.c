/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/02 14:04:50 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_stack	a;
	static t_stack	b;
	t_arr			map;
	if (argc < 2)
		return (0);
	check_empty(--argc, ++argv);
	validate_input(&a, argc, argv);
	if (!issorted(&a))
	{
		map = (t_arr){.arr = dup_stack_to_array_sort(&a),
			.size = a.capacity,
			.last_pivot = 0};
		if (!map.arr)
			return (free_elements(&a), submit_error(), 2);
		if (a.capacity == 2)
			sort_two(&a, A);
		else if (a.capacity == 3)
			sort_three(&a);
		else if (a.capacity <= 5)
			sort_five(&a, &b);
		else if (a.capacity > 5)
			sort_big(&a, &b, &map);
	}
	print_stacks(&a, &b);
	return (free_elements(&a), free(map.arr), 0);
}
