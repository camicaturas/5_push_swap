/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/02/02 18:32:42 by cberneri         ###   ########.fr       */
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

/*
 * Create the stack with the command line values
 * Checks are embedded in the creation itslef
 * 		~Duplicate values
 * 		~Over|Underflow
 * 		~Syntax errors
 *
 * 	 Flag is useful cause if true
 * Create the stack with the command line values
 * Checks are embedded in the creation itslef
 * 		~Duplicate values
 * 		~Over|Underflow
 * 		~Syntax errors, i have the argv in the HEAP to free
 *
*/

/*
FUNCION DE OCEANO
void	stack_create(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
*/


/* CREAMOS el numero en las lista para el stack*/
t_stack_node	*stack_new(int stack_val)
{
	t_stack_node	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = stack_val;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack_node	*stack_create(int ac, char *argv[])
{
	int			i;
	t_stack_node		*stack_a;
	long int	nb;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_exit(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
