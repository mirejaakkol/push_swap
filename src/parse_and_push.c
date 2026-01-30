#include "push_swap.h"

void	push(t_stack *a, t_stack *b, int element)
{
	t_node	*node;
	t_node	*temp;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	node->element = element;
	node->next = NULL;
	if (a->top == NULL)
		a->top = node;
	else
	{
		temp = a->top;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

int	parse_and_push(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	int		sign;
	long	value;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			skip_whitespace(&arg);
			if (*arg == '\0')
				break;
			sign = check_sign(&arg);
			value = parse_digits(&arg, a, b) * sign;
			if (check_range(value) == -1 || \
					check_duplicate(a, (int)value) == -1)
				return (-1);
			push(a, b, (int)value);
			skip_whitespace(&arg);
		}
		i++;
	}
	return (0);
}