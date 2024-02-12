/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/02/12 16:45:28 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int	stack_length;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a = stack_create(&stack_a, argc, argv);
	if (!stack_is_sorted(stack_a))
	{
		stack_length = stack_length(stack_a);
		if (stack_length == 2)
			sa(&stack_a, 0, stack_length);
		else if (stack_length == 3)
			tiny_sort(stack_a);
		else
			//push_swap(&stack_a, &stack_b, stack_length);
			push_swap(&stack_a, &stack_b);
	}
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
