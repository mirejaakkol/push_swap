#include "push_swap.h"

static int	find_position(int *array, int size, int position)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == position)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*stack_array(t_stack *a, int size)
{
	t_node	*current;
	int		*array;
	int		i;

	current = a->top;
	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (current)
	{
		array[i++] = current->element;
		current = current->next;
	}
	return (array);
}

void	simplify_list(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		*array;
	int		size;

	size = stack_size(a);
	array = stack_array(a, size);
	if (!array)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	sort_array(array, size);
	current = a->top;
	while (current)
	{
		current->element = find_position(array, size, current->element);
		current = current->next;
	}
	free(array);
}