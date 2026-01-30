#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (!a || !b || parse_and_push(a, b, argc, argv) == -1)
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (stack_size(a) <= 1 || stack_sorted_check(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	else
		sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}