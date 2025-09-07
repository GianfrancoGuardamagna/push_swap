#include "push_swap.h"

static int position_biggest(t_stack **stack)
{
    int i;
    int tmp;
    int max_value;
    t_stack *current;

    if(!(*stack))
        return -1;
    i = 0;
    tmp = 0;
    max_value = (*stack)->value;
    current = (*stack);
    while (current)
    {
        if(current->value > max_value)
        {
            max_value = current->value;
            tmp = i;
        }
        i++;
        current = current->next;
    }
    return tmp;
}

void small_analisis(t_stack **stack)
{
    int position;

    if(stack_sorted(*stack))
        return;
    position = position_biggest(stack);
    if(position == 0)
    {
        ra(stack);
        if(!stack_sorted(*stack))
            sa(*stack);
    }
    else if(position == 1)
    {
        rra(stack);
        if(!stack_sorted(*stack))
            sa(*stack);
    }
    else if(position == 2)
    {
        sa(*stack);
    }
}