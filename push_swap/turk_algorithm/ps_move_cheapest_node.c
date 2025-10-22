/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_cheapest_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 04:06:47 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 18:22:41 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_move_cheapest_node(t_stack *stack, t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack);
		cost_a++;
		cost_b++;
	}
	ps_rotate_single_stack(stack, cost_a, 'a');
	ps_rotate_single_stack(stack, cost_b, 'b');
}

void	ps_rotate_single_stack(t_stack *stack, int cost, char which_stack)
{
	while (cost > 0)
	{
		if (which_stack == 'a')
			ra(stack, 1);
		else if (which_stack == 'b')
			rb(stack, 1);
		cost--;
	}
	while (cost < 0)
	{
		if (which_stack == 'a')
			rra(stack, 1);
		else if (which_stack == 'b')
			rrb(stack, 1);
		cost++;
	}
}
