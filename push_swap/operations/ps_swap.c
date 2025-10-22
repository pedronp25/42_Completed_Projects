/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:05:13 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/21 17:57:30 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int print)
{
	t_node	*first;
	t_node	*second;

	first = stack->a;
	if (!first || !first->next)
		return ;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int print)
{
	t_node	*first;
	t_node	*second;

	first = stack->b;
	if (!first || !first->next)
		return ;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	sa(stack, 0);
	sb(stack, 0);
	write(1, "ss\n", 3);
}
