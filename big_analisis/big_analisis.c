#include "push_swap.h"

// int find_cheapest_element(t_stack *stack_a, t_stack *stack_b)
// {
//     t_stack *current;
//     int cheapest_value;
//     int min_cost;
//     int current_cost;
//     current = stack_b;
//     cheapest_value = current->value;
//     min_cost = calculate_cost(stack_a, stack_b, current->value);
//     while (current)
//     {
//         current_cost = calculate_cost(stack_a, stack_b, current->value);
//         if (current_cost < min_cost)
//         {
//             min_cost = current_cost;
//             cheapest_value = current->value;
//         }
//         current = current->next;
//     }
//     return (cheapest_value);
// }

void ordering_stack(t_stack **stack)
{
    t_stack *copy = (*stack);
    int min = copy->value;
    int threshold = stack_len((*stack)) / 2;
    int pos = 0;
    int min_pos = 0;

    while(copy)
    {
        if(copy->value < min)
        {
            min = copy->value;
            min_pos = pos;
        }
        pos++;
        copy = copy->next;
    }
    if(min_pos <= threshold)
        while((*stack) && (*stack)->value != min)
            ra(stack);
    else if(min_pos > threshold)
        while((*stack) && (*stack)->value != min)
            rra(stack);
}

void big_analisis(t_stack **stack_a, t_stack **stack_b)
{
    int cheapest;
    int min_cost;
    int cost;
    t_stack *current;

    while (stack_len(*stack_a) > 3)
        pb(stack_a, stack_b);
    
    small_analisis(stack_a);

    while (*stack_b)
    {
        cheapest = (*stack_b)->value;
        min_cost = calculate_cost(*stack_a, *stack_b, cheapest);
        current = (*stack_b)->next;
        while(current)
        {
            cost = calculate_cost(*stack_a, *stack_b, current->value);
            if (cost < min_cost)
            {
                min_cost = cost;
                cheapest = current->value;
            }
            current = current->next;
        }
        execute_cheapest_move(stack_a, stack_b, cheapest);
    }
    ordering_stack(stack_a);
    // ft_printf("Stack_a\n");
    // while(*stack_a)
    // {
    //     ft_printf("%d\n", (*stack_a)->value);
    //     *stack_a = (*stack_a)->next;
    // }
    // ft_printf("Stack_b\n");
    // while(*stack_b)
    // {
    //     ft_printf("%d\n", (*stack_b)->value);
    //     *stack_b = (*stack_b)->next;
    // }
}
