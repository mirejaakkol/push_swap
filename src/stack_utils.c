#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack->top = NULL;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next_node;

	if (!stack)
		return ;
	temp = stack->top;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	free(stack);
}

int	stack_size(t_stack *stack)
{
	t_node	*temp;
	int		size;

	temp = stack->top;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	stack_sorted_check(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp && temp->next)
	{
		if (temp->element > temp->next->element)
			return (0);
		temp = temp->next;
	}
	return (1);
}