/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/03/06 13:17:24 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_wordlen(char const *s, char c, int i);
size_t				ft_count_word(char const *s, char c);
void				ft_putstr(char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
long int			ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
void				pa(t_stack_node **stack_a, t_stack_node **stack_b);
void				pb(t_stack_node **stack_b, t_stack_node **stack_a);
void				rra(t_stack_node **stack_a);
void				rrb(t_stack_node **stack_b);
void				rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void				ra(t_stack_node **stack_a);
void				rb(t_stack_node **stack_b);
void				rr(t_stack_node **stack_a, t_stack_node **stack_b);
void				sa(t_stack_node	**stack_a);
void				sb(t_stack_node	**stack_b);
void				ss(t_stack_node **stack_a, t_stack_node **stack_b);
void				exit_error(t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node		*stack_new_node(int stack_val);
bool				stack_is_sorted(t_stack_node *stack_a);
int					is_sign(char c);
int					is_digit(char c);
int					input_check(char **av);
int					nbstr_cmp(const char *s1, const char *s2);
void				stack_add_bottom(t_stack_node **stack,
						t_stack_node *new_node);
void				set_position(t_stack_node *stack);
void				set_price(t_stack_node *stack_a, t_stack_node *stack_b);
void				set_cheapest(t_stack_node *stack_b);
void				set_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void				finish_rotation(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name);
void				push_swap(t_stack_node **stack_a, t_stack_node **stack_b);
void				stack_free(t_stack_node **stack);
int					stack_size(t_stack_node *stack);
void				sort_three(t_stack_node **stack_a);
void				sort_five(t_stack_node **stack_a, t_stack_node **stack_b);
void				stack_add_bottom(t_stack_node **stack, t_stack_node *new);
t_stack_node		*get_last_node(t_stack_node *head);
t_stack_node		*get_cheapest_node(t_stack_node *stack);
t_stack_node		*get_stack_last(t_stack_node *stack);
t_stack_node		*get_stack_second_to_last(t_stack_node *stack);
t_stack_node		*find_smallest_node(t_stack_node *stack);
t_stack_node		*find_highest_node(t_stack_node *stack);
t_stack_node		*stack_create(int ac, char *argv[]);
#endif