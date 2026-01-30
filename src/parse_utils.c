#include "push_swap.h"

void	skip_whitespace(char **arg)
{
	while (**arg == ' ' || (**arg >= 9 && **arg <= 13))
		(*arg)++;
}

int	check_sign(char **arg)
{
	int	sign;

	sign = 1;
	if (**arg == '-' || **arg == '+')
	{
		if (**arg == '-')
			sign = -1;
		(*arg)++;
	}
	return (sign);
}

long	parse_digits(char **arg, t_stack *a, t_stack *b)
{
	long	value;
	int		digit_found;

	value = 0;
	digit_found = 0;
	while (**arg >= '0' && **arg <= '9')
	{
		digit_found = 1;
		if (value > INT_MAX || value < INT_MIN)
			return (value);
		value = value * 10 + (**arg - '0');
		(*arg)++;
	}
	if ((!digit_found || (**arg && (**arg != ' ' && \
						(**arg < 9 || **arg > 13)))))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	return (value);
}

int	check_range(long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}

int	check_duplicate(t_stack *stack, int value)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->element == value)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		temp = temp->next;
	}
	return (0);
}