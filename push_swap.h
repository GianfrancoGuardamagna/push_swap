/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguardam <gguardam@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:39:15 by gguardam          #+#    #+#             */
/*   Updated: 2025/09/09 14:39:16 by gguardam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/*Utils*/
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack_a);
int		error_checker(char **argv);
void	free_split(char **tokens);

/*Instructions Swap*/
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/*Instructions Push*/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/*Instructions Rotate*/
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*Instructions Reverse Rotate*/
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*Small Analisis*/
void	small_analisis(t_stack **stack);

/*Big Analisis*/
void	big_analisis(t_stack **stack_a, t_stack **stack_b);
int		find_cheapest_element(t_stack *stack_a, t_stack *stack_b);

/*Big Analisis Execute Cheapest Move*/
void	execute_cheapest_move\
(t_stack **stack_a, t_stack **stack_b, int cheapest);
void	set_stack_a(t_stack **stack, int cheapest);
void	set_stack_b(t_stack **stack, int cheapest);

/*Big Analisis Utils*/
int		cost_in_stack(t_stack *stack, int value);
int		calculate_cost(t_stack *stack_a, t_stack *stack_b, int value);
int		find_target(t_stack *stack, int value_in_b);
void	ordering_stack(t_stack **stack_a);

#endif
