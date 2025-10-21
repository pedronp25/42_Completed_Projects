/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:30:01 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/27 19:22:48 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	x;
	int	temp;

	x = 0;
	while (x < (size / 2))
	{
		temp = tab[x];
		tab[x] = tab[size - x - 1];
		tab[size - x - 1] = temp;
		x++;
	}
}

/*
int	main(void)
{
	int	a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	b;
	int	size_arr;

	size_arr = sizeof(a) / sizeof(int);

	b = 0;
	while (b != size_arr)
	{
		printf("%i ", a[b]);
		b++;
	}
	printf("\n");

	ft_rev_int_tab(a, size_arr);

	b = 0;
	while (b != size_arr)
	{
		printf("%i ", a[b]);
		b++;
	}
	printf("\n");
}
*/
