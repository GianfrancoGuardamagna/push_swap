#include "../push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !*stack || !((*stack)->next))
        return;
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}