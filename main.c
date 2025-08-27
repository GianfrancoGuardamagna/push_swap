#include "push_swap.h"

static void free_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    t_stack *next;

    current = *stack_a;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack_a = NULL;

    current = *stack_b;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack_b = NULL;
}


int main(int argc, char **argv)
{
    int i;
    unsigned int len;
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *new_node;

    if (argc < 2 || !argv[1][0])
        return (1);

    //1 parametro exclusivo o pueden ser varios?
    // if(!error_checker(argc, argv))
    // {
    //     perror("Error");
    //     return (1);
    // }

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while (i < argc)
    {
        new_node = ft_lstnew(ft_atoi(argv[i]));
        if (!new_node)
        {
            printf("Error: memory allocation failed\n");
            free_stack(&stack_a, &stack_b);
            return (1);
        }
        ft_lstadd_back(&stack_a, new_node);
        i++;
    }

    len = stack_len(stack_a);
    if(!stack_sorted(stack_a))
    {
        if(len == 2)
            sa(stack_a);
        else if(len == 3)
            small_analisis(&stack_a);
        else
            big_analisis(&stack_a, &stack_b);
            //turk_algorithm(&stack_a, &stack_b);
    }
    free_stack(&stack_a, &stack_b);
    return (0);
}
