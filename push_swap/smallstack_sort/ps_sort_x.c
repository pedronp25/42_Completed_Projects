/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:45:47 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 18:41:22 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_sort_2(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value)
		sa(stack, 1);
}

void	ps_sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

void	ps_sort_4(t_stack *stack)
{
	int	pos;

	pos = ps_find_min_pos(stack);
	ps_rotate_to_top(stack, pos);
	pb(stack, 1);
	ps_sort_3(stack);
	pa(stack, 1);
}

void	ps_sort_5(t_stack *stack)
{
	int	pos;

	pos = ps_find_min_pos(stack);
	ps_rotate_to_top(stack, pos);
	pb(stack, 1);
	ps_sort_4(stack);
	pa(stack, 1);
}
