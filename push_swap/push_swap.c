/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:35:43 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/26 16:21:45 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		arr_len;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ps_error(stack);
	stack->array.str_arr = ps_args_check(stack, argc, argv);
	stack->array.int_arr = ps_validate_str_arr(stack,
			stack->array.str_arr, &arr_len);
	ps_init_stacks(stack, stack->array.int_arr, arr_len);
	if (ps_sorted(stack))
		ps_success(stack);
	else if (stack->len_a <= 5)
		ps_smallstack_sort(stack);
	else
		ps_turk(stack);
	ps_success(stack);
}

int	ps_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
