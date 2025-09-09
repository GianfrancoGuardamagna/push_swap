#include "push_swap.h"

static void	free_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*next;

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

static void	loading_stack(t_stack **stack_a, t_stack **stack_b, char **argv)
{
	t_stack	*new_node;
	char	**input;
	int		i;

	input = ft_split(argv[1], ' ');
	if (!input)
		return ;
	i = 0;
	while (input[i])
	{
		new_node = ft_lstnew(ft_atoi(input[i]));
		if (!new_node)
		{
			ft_printf("Error: memory allocation failed\n");
			free_stack(stack_a, stack_b);
			free_split(input);
			return ;
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	free_split(input);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	unsigned int	len;

	if (argc < 2)
		return (1);
	if (error_checker(argv) || argc != 2)
		return (ft_printf("Error\n"));
	stack_a = NULL;
	stack_b = NULL;
	loading_stack(&stack_a, &stack_b, argv);
	len = stack_len(stack_a);
	if (!stack_sorted(stack_a))
	{
		if (len == 2)
			sa(stack_a);
		else if (len == 3)
			small_analisis(&stack_a);
		else
			big_analisis(&stack_a, &stack_b);
	}
	free_stack(&stack_a, &stack_b);
	return (0);
}
