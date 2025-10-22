/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:06:02 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 18:43:47 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_calculate_cost(t_stack *stack)
{
	t_node	*current;
	int		pos_b;
	int		target_pos;

	current = stack->b;
	pos_b = 0;
	while (current)
	{
		current->cost_b = ps_get_cost_b(stack, pos_b);
		target_pos = ps_get_target_pos_a(stack, current->value);
		current->cost_a = ps_get_cost_a(stack, target_pos);
		current = current->next;
		pos_b++;
	}
}

int	ps_get_cost_b(t_stack *stack, int pos)
{
	if (pos <= stack->len_b / 2)
		return (pos);
	else
		return (pos - stack->len_b);
}

int	ps_get_target_pos_a(t_stack *stack, int b_val)
{
	t_node	*current;
	int		min_pos;
	int		target_pos;
	int		best_val;
	int		pos;

	current = stack->a;
	min_pos = ps_find_smallest_value(current);
	target_pos = -1;
	pos = 0;
	while (current)
	{
		if (current->value > b_val && (target_pos == -1
				|| current->value < best_val))
		{
			best_val = current->value;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (target_pos != -1)
		return (target_pos);
	return (min_pos);
}

int	ps_find_smallest_value(t_node *current)
{
	int	min_val;
	int	min_pos;
	int	pos;

	min_val = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	ps_get_cost_a(t_stack *stack, int target_pos)
{
	if (target_pos <= stack->len_a / 2)
		return (target_pos);
	else
		return (target_pos - stack->len_a);
}
