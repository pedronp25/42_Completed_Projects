/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:14:47 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:12 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>
int	main(void)
{
	int	x;
	int	y;

	x = 42;
	y = 84;
	printf("%i/%i", x, y);
	printf("\n");

	ft_swap(&x, &y);

	printf("%i/%i", x, y);
	printf("\n");
}
*/
