#include "../push_swap.h"

static void push(t_stack **stack_f, t_stack **stack_s)
{
    t_stack *temp;
    
    if (!*stack_f)
        return;

    temp = *stack_f;

    *stack_f = (*stack_f)->next;

    temp->next = *stack_s;
    *stack_s = temp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    printf("pb\n");
}
