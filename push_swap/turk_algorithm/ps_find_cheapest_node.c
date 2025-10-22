/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_cheapest_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 03:30:28 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/23 22:18:49 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ps_find_cheapest_node(t_node *current)
{
	t_node	*cheapest_node;
	int		lowest_cost;
	int		total_cost;

	cheapest_node = current;
	lowest_cost = ps_abs(current->cost_a) + ps_abs(current->cost_b);
	current = current->next;
	while (current)
	{
		total_cost = ps_calc_node_cost(current);
		if (total_cost < lowest_cost)
		{
			lowest_cost = total_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

int	ps_calc_node_cost(t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return (ps_max(ps_abs(cost_a), ps_abs(cost_b)));
	else
		return (ps_abs(cost_a) + ps_abs(cost_b));
}

int	ps_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ps_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}
