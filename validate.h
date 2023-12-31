/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:54:02 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:54:03 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include <stdio.h>     // For exit macros
# include <sys/types.h> // For ssize_t
# include <stdbool.h>   // For bool
# include <unistd.h>    // For write
# include <stdlib.h>    // For exit
# include "stack.h"
# include "hash_table.h"

/*---- INPUT PARSING ----*/
char	*join_input_space(int inputc, char *inputv[]);
t_stack	*validate_input(t_stack *a, int argc, char *argv[]);
void	submit_error(void);
void	check_empty(int inputc, char *inputv[]);
void	set_check_insert(t_stack *a);
bool	set_insert(t_entry *set, int value, size_t set_size);
#endif // !VALIDATE_H
