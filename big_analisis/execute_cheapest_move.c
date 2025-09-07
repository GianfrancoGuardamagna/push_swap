#include "../push_swap.h"

void set_stack_a(t_stack **stack, int cheapest)
{
    int threshold;
    int pos;
    int value;
    t_stack *current;

    pos = 0;
    threshold = stack_len(*stack) / 2;
    value = find_target(*stack, cheapest);
    current = (*stack);
    while(current && current->value != value)
    {
        pos++;
        current = current->next;
    }
    if(pos <= threshold)
    {
        while((*stack) && (*stack)->value != value)
            ra(stack);
    }
    else if(pos > threshold)
    {
        while((*stack) && (*stack)->value != value)
            rra(stack);
    }
}

void set_stack_b(t_stack **stack, int cheapest)
{
    int pos;
    int threshold;
    t_stack *current;
    
    pos = 0;
    threshold = stack_len(*stack) / 2;
    current = *stack;
    while (current && current->value != cheapest)
    {
        pos++;
        current = current->next;
    }
    if (pos <= threshold)
    {
        while ((*stack)->value != cheapest)
            rb(stack);
    }
    else
    {
        while ((*stack)->value != cheapest)
            rrb(stack);
    }
}

void set_stacks(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
    int target = find_target(*stack_a, cheapest);

    if((cost_in_stack(*stack_b, cheapest) > 0) && (cost_in_stack(*stack_a, target) > 0))
    {
        while ((*stack_a)->value != target && (*stack_b)->value != cheapest)
            rr(stack_a, stack_b);
    }
    else if((cost_in_stack(*stack_b, cheapest) < 0) && (cost_in_stack(*stack_a, target) < 0))
    {
        while ((*stack_a)->value != target && (*stack_b)->value != cheapest)
            rrr(stack_a, stack_b);
    }
}

void execute_cheapest_move(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
    set_stacks(stack_a, stack_b, cheapest);
    set_stack_b(stack_b, cheapest);
    set_stack_a(stack_a, cheapest);
    pa(stack_a, stack_b);
}
