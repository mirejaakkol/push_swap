#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_node {
	struct s_node	*next;
	int				element;
}	t_node;

typedef struct s_stack {
	t_node	*top;
}	t_stack;

/*Operations*/
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
/*Parse and push*/
void	push(t_stack *a, t_stack *b, int element);
int		parse_and_push(t_stack *a, t_stack *b, int argc, char **argv);
/*Parse utils*/
void	skip_whitespace(char **arg);
int		check_sign(char **arg);
long	parse_digits(char **arg, t_stack *a, t_stack *b);
int		check_range(long value);
int		check_duplicate(t_stack *a, int value);
/*Stack utils*/
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_sorted_check(t_stack *stack);
/*Stack sorting*/
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	simplify_list(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
/*Main*/
int		main(int argc, char **argv);

#endif