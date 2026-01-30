#include "push_swap.h"

static int	find_max_bits(t_stack *a)
{
	t_node	*current;
	int		max;
	int		max_bits;

	if (!a || !a->top)
		return (0);
	current = a->top;
	max = abs(current->element);
	while (current)
	{
		if (abs(current->element) > max)
			max = abs(current->element);
		current = current->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	bit;

	size = stack_size(a);
	max_bits = find_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			bit = a->top->element;
			if (((bit >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (stack_size(b) > 0)
			pa(a, b);
		i++;
	}
}