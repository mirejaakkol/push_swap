#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->top && stack_size(b) > 0)
	{
		temp = b->top;
		b->top = b->top->next;
		temp->next = a->top;
		a->top = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->top && stack_size(a) > 0)
	{
		temp = a->top;
		a->top = a->top->next;
		temp->next = b->top;
		b->top = temp;
	}
	ft_printf("pb\n");
}