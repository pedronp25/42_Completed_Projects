/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 03:32:14 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/05 03:52:50 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	x;

	x = 0;
	while (x < length)
	{
		(*f)(tab[x]);
		x++;
	}
}

/*
#include <stdio.h>
void	fodase(int aaaaaaaaaaaaaaaaa)
{
	printf("%d\n", aaaaaaaaaaaaaaaaa);
}

int	main(void)
{
	int	len = 5;
	int	arr[5] = {1, 2, 3, 4, 5};

	ft_foreach(arr, len, &fodase);
}
*/
