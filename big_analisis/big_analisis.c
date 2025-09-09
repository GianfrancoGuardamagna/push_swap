#include "../push_swap.h"

void	ordering_stack(t_stack **stack)
{
	t_stack	*copy;
	int		min;
	int		threshold;
	int		pos;
	int		min_pos;

	copy = (*stack);
	min = copy->value;
	threshold = stack_len((*stack)) / 2;
	pos = 0;
	min_pos = 0;
	while (copy)
	{
		if (copy->value < min)
		{
			min = copy->value;
			min_pos = pos;
		}
		pos++;
		copy = copy->next;
	}
	while ((*stack) && (*stack)->value != min && min_pos <= threshold)
		ra(stack);
	while ((*stack) && (*stack)->value != min && min_pos > threshold)
		rra(stack);
}

static int	calculating(t_stack **stack_a, t_stack **stack_b)
{
	int		min_cost;
	int		cost;
	int		cheapest;
	t_stack	*current;

	cheapest = (*stack_b)->value;
	min_cost = calculate_cost(*stack_a, *stack_b, cheapest);
	current = (*stack_b)->next;
	while (current)
	{
		cost = calculate_cost(*stack_a, *stack_b, current->value);
		if ((cost < min_cost) || \
((cost == min_cost) && (current->value > cheapest)))
		{
			min_cost = cost;
			cheapest = current->value;
		}
		current = current->next;
	}
	return (cheapest);
}

void	big_analisis(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;

	while (stack_len(*stack_a) > 3)
		pb(stack_a, stack_b);
	small_analisis(stack_a);
	while (*stack_b)
	{
		cheapest = calculating(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b, cheapest);
	}
	ordering_stack(stack_a);
}
