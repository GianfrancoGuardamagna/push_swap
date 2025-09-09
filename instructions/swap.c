#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_stack	*next_stack;
	int		temp;

	if ((!stack) || !(stack->next))
		return ;
	next_stack = stack->next;
	temp = stack->value;
	stack->value = next_stack -> value;
	next_stack->value = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
