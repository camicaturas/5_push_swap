/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/05 15:31:44 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	stack_middle;
	int	i;

	i = 0;
	if (stack == NULL)
		return ;
	stack_middle = stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (stack_middle >= i)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *stack_a,
							t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			highest_index;

	while (stack_b)
	{
		highest_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < highest_index)
			{
				highest_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (highest_index == LONG_MAX)
			stack_b->target_node = find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_price(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = stack_size(stack_a);
	length_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->push_price = stack_b->position;
		if (!(stack_b->above_median))
			stack_b->push_price = length_b - (stack_b->position);
		if (stack_b->target_node->above_median)
			stack_b->push_price += stack_b->target_node->position;
		else
			stack_b->push_price += length_a - (stack_b->target_node->position);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack_node *stack_b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_price < best_match_value)
		{
			best_match_value = stack_b->push_price;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest = true;
}

void	set_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}
