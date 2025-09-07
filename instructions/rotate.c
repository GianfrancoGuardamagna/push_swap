#include "../push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *tmp_stack;

    if((!stack) || !((*stack)->next))
        return;
    tmp_stack = *stack;
    (*stack) = (*stack)->next;
    tmp_stack->next = NULL;
    ft_lstadd_back(stack, tmp_stack);
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}
