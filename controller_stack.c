/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/02/12 10:56:01 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

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

int	stack_length(t_stack_node *stack)
{
	int	length;

	if (NULL == stack)
		return (0);
	length = 0;
	while (stack)
	{
		++len;
		stack = stack->next;
	}
	return (length);
}

void	stack_new(t_stack_node **stack_a, int stack_val)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (stack_a == NULL)
		return (NULL);
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = stack_val;
	new_node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}

}

t_stack_node	*stack_create(t_stack_node **stack_a, int ac, char *argv[])
{
	int			i;
	long int	number;

	number = 0;
	i = 1;
	while (i < ac)
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_exit(&stack_a, NULL);
		stack_a = stack_new(stack_a, (int)number);
		i++;

/*
		if (i == 1)
			stack_a = stack_new(stack_a, (int)number);
		else
			stack_add_bottom(&stack_a, stack_new((int)number));
		i++;
*/

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
