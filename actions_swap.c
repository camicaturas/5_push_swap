/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/05 14:13:26 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node *head)
{
	int	temp;

	if (head == NULL || head->next == NULL)
		return ;
	temp = head->value;
	head->value = head->next->value;
	head->next->value = temp;
	temp = head->index;
	head->index = head->next->index;
	head->next->index = temp;
}

void	sa(t_stack_node	**stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack_node	**stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
