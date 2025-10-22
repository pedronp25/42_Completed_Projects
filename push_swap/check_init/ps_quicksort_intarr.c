/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort_intarr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:42:27 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/18 01:44:56 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_quicksort_int_arr(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ps_partition(arr, low, high);
		ps_quicksort_int_arr(arr, low, pi - 1);
		ps_quicksort_int_arr(arr, pi + 1, high);
	}
}

int	ps_partition(int *arr, int low, int high)
{
	int	pivot;
	int	x;
	int	y;

	pivot = arr[high];
	x = low - 1;
	y = low;
	while (y < high)
	{
		if (arr[y] <= pivot)
		{
			x++;
			ps_swap(&arr[x], &arr[y]);
		}
		y++;
	}
	ps_swap(&arr[x + 1], &arr[high]);
	return (x + 1);
}

void	ps_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
