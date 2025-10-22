/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate_nums_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 07:21:24 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/26 00:37:28 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_strarr_len(char **str_arr)
{
	int	x;

	x = 0;
	while (str_arr && str_arr[x])
		x++;
	return (x);
}

long	ps_atol(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ps_check_duplicates(t_stack *stack, int	*arr, int len)
{
	int	x;
	int	*copy_arr;

	copy_arr = ps_copy_array(stack, arr, len);
	ps_quicksort_int_arr(copy_arr, 0, len - 1);
	x = 0;
	while (x < len -1)
	{
		if (copy_arr[x] == copy_arr[x + 1])
		{
			free(copy_arr);
			ps_error(stack);
		}
		x++;
	}
	free(copy_arr);
}

int	*ps_copy_array(t_stack *stack, int *arr, int len)
{
	int	x;
	int	*copy_arr;

	copy_arr = ft_calloc(len, sizeof(int));
	if (!copy_arr)
		ps_error(stack);
	x = 0;
	while (x < len)
	{
		copy_arr[x] = arr[x];
		x++;
	}
	return (copy_arr);
}
