#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (a->top && a->top->next)
	{
		last = a->top;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = a->top;
		a->top = last;
	}
	ft_printf("rra\n");
}