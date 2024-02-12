/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/02/12 16:45:11 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

static void	swap(t_stack_node **head, stack_length)
{
	if (*head == NULL || head == NULL|| stack_length == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, bool check, stack_length)
{
	swap(a, stack_length);
	if (check == 0)
		write(1, "SA\n", 3);
}

void	sb(t_stack_node	**b, bool check, stack_length)
{
	swap(b, stack_length);
	if (check == 0)
		write(1, "SB\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool check, stack_length)
{
	swap(a, stack_length);
	swap(b, stack_length);
	if (!check)
		write(1, "SS\n", 3);
}
