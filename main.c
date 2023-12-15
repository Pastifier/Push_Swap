#include "stack.h"

int	main(int argc, char *argv[])
{
	(void)argc; (void)argv;

	t_node *first = create_node(1);
	t_node *to_push = create_node(2);
	t_node *first2 = create_node(1);
	t_node *to_push2 = create_node(2);
	t_stack test = init_stack(first);
	t_stack test2 = init_stack(first2);

	stack_push(&test, to_push);
	stack_push(&test2, to_push2);
	while ((test.top))
	{
		printf("%d\n", (test.top)->value);
		test.top = (test.top)->below;
	}
	t_node *popped = stack_pop(&test2);
	printf("\n\npopped value: %d\n", popped->value);
	while((test2.top))
	{
		printf("%d\n", (test2.top)->value);
		test2.top = (test2.top)->below;
	}
	return (0);
}
