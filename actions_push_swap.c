/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:02 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **stack_a,
						t_stack_node **stack_b,
						t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rr(stack_a, stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
}

static void	reverse_rotate_both(t_stack_node **stack_a,
								t_stack_node **stack_b,
								t_stack_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rrr(stack_a, stack_b);
	set_position(*stack_a);
	set_position(*stack_b);
}

void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack_node **stack_a,
						t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b);
}

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*smallest;
	int				stack_length;

	stack_length = stack_size(*stack_a);
	if (stack_length == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (stack_length-- > 3)
			pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_position(*stack_a);
	smallest = find_smallest_node(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}
