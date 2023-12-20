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

// TODO:
// create input validation.
#include "push_swap.h"
#include "validate.h"
#include <stdlib.h>

void	submit_error(void)
{
	return ((void)write(2, "Error\n", 6));
}
