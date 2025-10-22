/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:42:16 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 17:54:40 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack, int print)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = stack->a;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->a;
	stack->a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int print)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = stack->b;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->b;
	stack->b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack	*stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	write(1, "rrr\n", 4);
}
