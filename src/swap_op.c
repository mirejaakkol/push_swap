#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top && a->top->next)
	{
		temp = a->top->element;
		a->top->element = a->top->next->element;
		a->top->next->element = temp;
	}
	ft_printf("sa\n");
}