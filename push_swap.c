/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/01/31 17:14:06 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	stack_node	*stack_a;
	stack_node	*stack_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a = stack_create(argc, argv);
	stack_b = NULL;

	
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&a, false);
		else if (stack_len(stack_a) == 3)
			tiny_sort(stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
