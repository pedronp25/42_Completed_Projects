/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:05:53 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 17:57:50 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, int print)
{
	t_node	*first;
	t_node	*last;

	first = stack->a;
	if (!first || !first->next)
		return ;
	stack->a = first->next;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int print)
{
	t_node	*first;
	t_node	*last;

	first = stack->b;
	if (!first || !first->next)
		return ;
	stack->b = first->next;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack	*stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 3);
}
