#include "../push_swap.h"

static void swap(t_stack *stack)
{
    int temp;
    t_stack *next_stack;

    if((!stack) || !(stack->next))
        return;
    next_stack = stack->next;
    temp = stack->value;
    stack->value = next_stack -> value;
    next_stack->value = temp;
}

void sa(t_stack *stack_a)
{
    swap(stack_a);
    printf("sa\n");
}

void sb(t_stack *stack_b)
{
    swap(stack_b);
    printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}
