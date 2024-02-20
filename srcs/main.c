/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/19 07:36:37 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	static t_stack	a;
	static t_stack	b;

	if (argc < 2)
		return (0);
	check_empty(--argc, ++argv);
	validate_input(&a, argc, argv);
	if (!issorted(&a))
	{
		if (a.capacity == 2)
			sort_two(&a, A);
		else if (a.capacity == 3)
			sort_three(&a);
		else if (a.capacity == 4 || a.capacity == 5)
			sort_five(&a, &b);
	}
	return (free_elements(&a), 0);
}
