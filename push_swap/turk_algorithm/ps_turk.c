/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 04:32:43 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 18:42:18 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_turk(t_stack *stack)
{
	t_node	*cheapest_node;

	while (stack->len_a != 3)
		pb(stack, 1);
	ps_sort_3(stack);
	while (stack->len_b)
	{
		ps_calculate_cost(stack);
		cheapest_node = ps_find_cheapest_node(stack->b);
		ps_move_cheapest_node(stack, cheapest_node);
		pa(stack, 1);
	}
	ps_final_rotation(stack);
}

void	ps_final_rotation(t_stack *stack)
{
	t_node	*current;
	int		lowest_value;
	int		x;
	int		node_pos;

	current = stack->a;
	lowest_value = current->value;
	x = 0;
	node_pos = 0;
	while (current)
	{
		if (current->value < lowest_value)
		{
			lowest_value = current->value;
			node_pos = x;
		}
		current = current->next;
		x++;
	}
	ps_ra_or_rra(stack, lowest_value, node_pos);
}

void	ps_ra_or_rra(t_stack *stack, int lowest_value, int pos)
{
	int	halfway;

	halfway = stack->len_a / 2;
	if (pos <= halfway)
		while (stack->a->value != lowest_value)
			ra(stack, 1);
	else
		while (stack->a->value != lowest_value)
			rra(stack, 1);
}
