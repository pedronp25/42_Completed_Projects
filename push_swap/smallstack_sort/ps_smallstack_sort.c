/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallstack_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:44:32 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 18:40:32 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_smallstack_sort(t_stack *stack)
{
	if (stack->len_a == 1)
		ps_success(stack);
	else if (stack->len_a == 2)
		ps_sort_2(stack);
	else if (stack->len_a == 3)
		ps_sort_3(stack);
	else if (stack->len_a == 4)
		ps_sort_4(stack);
	else if (stack->len_a == 5)
		ps_sort_5(stack);
}

int	ps_find_min_pos(t_stack *stack)
{
	int		min_value;
	int		min_pos;
	int		current_pos;
	t_node	*node;

	node = stack->a;
	min_value = node->value;
	min_pos = 0;
	current_pos = 0;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_pos = current_pos;
		}
		current_pos++;
		node = node->next;
	}
	return (min_pos);
}

void	ps_rotate_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->len_a / 2)
	{
		while (pos > 0)
		{
			ra(stack, 1);
			pos--;
		}
	}
	else
	{
		pos = stack->len_a - pos;
		while (pos > 0)
		{
			rra(stack, 1);
			pos--;
		}
	}
}
