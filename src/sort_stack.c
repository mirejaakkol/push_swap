#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 2)
	{
		if (a->top->element > a->top->next->element)
			sa(a);
	}
	else if (stack_size(a) == 3)
		sort_three(a);
	else if (stack_size(a) == 4)
		sort_four(a, b);
	else if (stack_size(a) == 5)
		sort_five(a, b);
	else
	{
		simplify_list(a, b);
		radix_sort(a, b);
	}
}