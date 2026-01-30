#include "push_swap.h"

static int	find_position_of_smallest(t_stack *a)
{
	t_node		*current;
	int			smallest;
	int			position;
	int			i;

	current = a->top;
	smallest = INT_MAX;
	position = 0;
	i = 0;
	while (current)
	{
		if (current->element < smallest)
		{
			smallest = current->element;
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}

static void	rotate_to_top_a(t_stack *a, int position)
{
	int	size;
	int	i;

	size = stack_size(a);
	if (position <= size / 2)
	{
		i = 0;
		while (i < position)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - position))
		{
			rra(a);
			i++;
		}
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	smallest_pos;

	smallest_pos = find_position_of_smallest(a);
	rotate_to_top_a(a, smallest_pos);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}