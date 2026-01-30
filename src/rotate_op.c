#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (a->top && a->top->next)
	{
		temp = a->top;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = a->top;
		a->top = a->top->next;
		temp->next->next = NULL;
	}
	ft_printf("ra\n");
}