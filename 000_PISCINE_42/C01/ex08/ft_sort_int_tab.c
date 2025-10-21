/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:35:59 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/27 19:46:08 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	i;
	int	temp;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - x - 1)
		{
			i = 0;
			if (tab[y] > tab[y + 1])
			{
				temp = tab[y];
				tab[y] = tab[y + 1];
				tab[y + 1] = temp;
			}
			else
				i++;
			y++;
		}
		x++;
	}
}

/*
int	main(void)
{
	int     a[10] = {10, 9, 8, 4, 5, 6, 7, 3, 2, 1};
	int     b;

	b = 0;
	while (b != (sizeof(a) / sizeof(int)))
	{
		printf("%i ", a[b]);
		b++;
	}
	printf("\n");

	ft_sort_int_tab(a, (sizeof(a) / sizeof(int)));

	b = 0;
	while (b != (sizeof(a) / sizeof(int)))
	{
		printf("%i ", a[b]);
		b++;
	}
	printf("\n");

}
*/
