/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate_nums_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:28:16 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/26 16:22:23 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ps_args_check(t_stack *stack, int argc, char **argv)
{
	if (argc == 1)
		ps_error(stack);
	else if (argc == 2)
	{
		stack->array.str_arr = ft_split(argv[1], ' ');
		if (!stack->array.str_arr || !stack->array.str_arr[0])
			ps_error(stack);
		return (stack->array.str_arr);
	}
	stack->array.str_arr = ft_calloc(argc, sizeof(char *));
	if (!stack->array.str_arr)
		ps_error(stack);
	ps_dup_argv_strings(stack, stack->array.str_arr, argv, argc);
	return (stack->array.str_arr);
}

void	ps_dup_argv_strings(t_stack *stack, char **matrix,
			char **argv, int argc)
{
	int	x;
	int	i;

	x = 0;
	while (x < argc - 1)
	{
		matrix[x] = ft_strdup(argv[x + 1]);
		if (!matrix[x])
		{
			i = 0;
			while (i < x)
				free(matrix[i++]);
			free(matrix);
			ps_error(stack);
		}
		x++;
	}
	matrix[x] = NULL;
}

int	*ps_validate_str_arr(t_stack *stack, char **str_arr, int *int_arr_len)
{
	int		x;

	x = 0;
	stack->array.int_arr = ft_calloc(ps_strarr_len(str_arr), sizeof(int));
	if (!stack->array.int_arr)
		ps_error(stack);
	x = ps_store_int_arr(stack, str_arr, stack->array.int_arr, x);
	ps_check_duplicates(stack, stack->array.int_arr, x);
	*int_arr_len = x;
	return (stack->array.int_arr);
}

int	ps_store_int_arr(t_stack *stack, char **str_arr, int *int_arr, int x)
{
	int		y;
	long	num;

	while (str_arr[x])
	{
		y = 0;
		if (str_arr[x][y] == '-' || str_arr[x][y] == '+')
			y++;
		if (!str_arr[x][y])
			ps_error(stack);
		while (str_arr[x][y])
		{
			if (str_arr[x][y] < '0' || str_arr[x][y] > '9')
				ps_error(stack);
			y++;
		}
		num = ps_atol(str_arr[x]);
		if (num > 2147483647 || num < -2147483648)
			ps_error(stack);
		int_arr[x] = (int)num;
		x++;
	}
	return (x);
}
