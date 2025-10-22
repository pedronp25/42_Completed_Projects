/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:59:46 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 17:54:58 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack, int print)
{
	t_node	*node;

	if (!stack->b)
		return ;
	node = stack->b;
	stack->b = node->next;
	node->next = stack->a;
	stack->a = node;
	stack->len_a++;
	stack->len_b--;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack, int print)
{
	t_node	*node;

	if (!stack->a)
		return ;
	node = stack->a;
	stack->a = node->next;
	node->next = stack->b;
	stack->b = node;
	stack->len_b++;
	stack->len_a--;
	if (print)
		write(1, "pb\n", 3);
}
