/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:31 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/27 10:46:39 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# ifndef WHITE_SPACE
#  define WHITE_SPACE " \n\t\r\v\f"
# endif // !WHITE_SPACE

/*--- CONST. -- DEFINES ---*/

# define SWAP 0
# define PUSH 1
# define ROTATE 2
# define REVERSE 3

# define A 1
# define B 0

/*----- ELEMENT -----*/
typedef struct s_elem
{
	int				value;
	struct s_elem	*above;
	struct s_elem	*below;
}	t_elem;

t_elem	*create_element(int value);

/*----- STACK -----*/
typedef struct s_stack
{
	size_t	capacity;
	t_elem	*top;
	t_elem	*bottom;
	int		least;
	int		greatest;
}	t_stack;

void	stack_swap(t_stack *stack, t_stack *other);
void	stack_cmp(t_stack *stack, t_elem *to_push);
void	stack_set_greatest(t_stack *stack);
void	stack_set_least(t_stack *stack);
void	stack_push(t_stack *stack, t_elem *to_push, t_stack *other);
void	stack_rotate(t_stack *stack, t_stack *other);
void	stack_rrotate(t_stack *stack, t_stack *other);
t_elem	*stack_pop(t_stack *stack, t_stack *other);

/*---- INPUT PARSING ----*/

typedef struct s_hash_table_entry
{
	int		value;
	bool	occupied;
}	t_entry;

char	*join_input_space(int inputc, char *inputv[]);
t_stack	*validate_input(t_stack *a, int argc, char *argv[]);
void	submit_error(void);
void	check_empty(int inputc, char *inputv[]);
bool	set_insert(t_entry *set, int value, size_t set_size);

/*--- PUSH_SWAP-OPERATIONS ---*/

void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*--- SORTING ---*/

bool	issorted(t_stack *stack);
void	sort_two(t_stack *stack, bool a_or_b);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	merge_sort(int *arr, size_t p, size_t r);
int		*dup_stack_to_array_sort(t_stack *stack);
bool	pivot_around_two_thirds(t_stack *stack, t_stack *other);
void	push_back_two_thirds(t_stack *stack, t_stack *other);

/*----- FREE -----*/
void	free_elements(t_stack *stack);
void	free_2d(char **arr);

/*--- DEBUGGING ---*/

void	print_stacks(t_stack *stack, t_stack *other);
#endif // !PUSH_SWAP_H
