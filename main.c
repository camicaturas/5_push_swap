/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/18 17:44:30 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				stack_len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!input_check(argv))
		exit_error(&stack_a, &stack_b);
	stack_a = stack_create(argc, argv);
	if (!stack_is_sorted(stack_a))
	{
		stack_len = stack_size(stack_a);
		if (stack_len == 2)
			sa(&stack_a);
		else if (stack_len == 3)
			sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
