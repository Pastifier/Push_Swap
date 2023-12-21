/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:07 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "validate.h"

int	main(int argc, char *argv[])
{
	t_stack	init;
	t_stack	*a;
	t_stack	b;

	check_empty(--argc, ++argv);
	if (argc > 1)
	{
		init = init_stack();
		b = init_stack();
		a = validate_input(&init, &b, --argc, ++argv);
		(void)a; // for now
	}
	return (0);
}
