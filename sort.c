/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/06 13:18:43 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_highest_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_five(t_stack_node **stack_a,
					t_stack_node **stack_b)
{
	int	stack_length;

	stack_length = stack_size(*stack_a);
	while (stack_length-- > 3)
	{
		set_nodes(*stack_a, *stack_b);
		finish_rotation(stack_a, find_smallest_node(*stack_a), 'a');
		pb(stack_b, stack_a);
	}
}
