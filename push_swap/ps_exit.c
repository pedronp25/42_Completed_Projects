/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:42:11 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/26 17:49:53 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(t_stack *stack)
{
	ft_printf("Error\n");
	ps_cleanup(stack);
	exit (1);
}

void	ps_success(t_stack *stack)
{
	ps_cleanup(stack);
	exit(0);
}

void	ps_cleanup(t_stack *stack)
{
	if (stack)
	{
		if (stack->a)
			ps_cleanup_stack(stack->a);
		if (stack->b)
			ps_cleanup_stack(stack->b);
		if (stack->array.int_arr)
			free(stack->array.int_arr);
		if (stack->array.str_arr)
			ps_free_strarr(stack->array.str_arr);
		free(stack);
	}
}

void	ps_free_strarr(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
		free(arr[x++]);
	free(arr);
}

void	ps_cleanup_stack(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
