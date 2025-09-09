/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:40:44 by gguardam          #+#    #+#             */
/*   Updated: 2025/09/09 14:40:47 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//How much it cost to put the value on the first position
int	cost_in_stack(t_stack *stack, int value)
{
	int		pos;
	int		threshold;
	int		len;
	t_stack	*current;

	pos = 0;
	current = stack;
	len = stack_len(stack);
	threshold = stack_len(stack) / 2;
	while (current)
	{
		if (current->value == value)
		{
			if (pos <= threshold)
				return (pos);
			else if (pos > threshold)
				return ((len - pos) * -1);
		}
		pos++;
		current = current->next;
	}
	return (-1);
}

/*It has to find the less bigger value to fit the value_in_b on top of that*/
int	find_target(t_stack *stack_a, int value_in_b)
{
	t_stack	*current;
	int		target_value;
	int		min_value;

	current = stack_a;
	target_value = 2147483647;
	min_value = 2147483647;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		if (current->value > value_in_b && current->value < target_value)
			target_value = current->value;
		current = current->next;
	}
	if (target_value == 2147483647)
		target_value = min_value;
	return (target_value);
}

//Calculate the cost of moving value in stack B to stack A by rotation.
int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int value_in_b)
{
	int	cost_a;
	int	cost_b;
	int	target_value;

	target_value = find_target(stack_a, value_in_b);
	cost_a = cost_in_stack(stack_a, target_value);
	cost_b = cost_in_stack(stack_b, value_in_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (cost_a < 0)
			cost_a = cost_a * -1;
		if (cost_b < 0)
			cost_b = cost_b * -1;
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	if (cost_a < 0)
		cost_a = cost_a * -1;
	if (cost_b < 0)
		cost_b = cost_b * -1;
	return (cost_a + cost_b);
}
