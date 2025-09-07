#include "../push_swap.h"

t_stack *ft_lstnew(int content)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = content;
    new_node->next = NULL;
    return (new_node);
}

void ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
    t_stack *current;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    current = *stack;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_node;
}

void ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

int stack_len(t_stack *stack)
{
    int i;

    i = 0;
    if(!stack)
        return i;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return i;
}

int stack_sorted(t_stack *stack_a)
{
    t_stack *current;

    if(!stack_a)
        return 1;

    current = stack_a;
    while(current)
    {
        if((current->next) && (current->value > current->next->value))
            return 0;
        current = current->next;
    }
    return 1;
}
