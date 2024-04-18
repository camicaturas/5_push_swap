/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/19 13:14:41 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	stack_add_bottom(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*end;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	end = get_stack_last(*stack);
	end->next = new;
}

t_stack_node	*stack_new_node(int stack_val)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof * new_node);
	if (new_node == NULL)
		return (NULL);
	new_node->value = stack_val;
	new_node->index = 0;
	new_node->position = -1;
	new_node->push_price = -1;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack_node	*stack_create(int ac, char *argv[])
{
	int				i;
	long int		number;
	t_stack_node	*stack_a;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < ac)
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new_node((int)number);
		else
			stack_add_bottom(&stack_a, stack_new_node((int)number));
		i++;
	}
	return (stack_a);
}

bool	stack_is_sorted(t_stack_node *stack_a)
{
	if (stack_a == NULL)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
