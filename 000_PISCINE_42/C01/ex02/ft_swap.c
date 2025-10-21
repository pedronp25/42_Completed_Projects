/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:04:42 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/02 15:08:13 by pedromig         ###   ########.fr       */
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
	int	x = 42;
	int	y = 24;

	printf("Original 'a' value: %i\n", x);
	printf("Original 'b' value: %i\n", y);

	ft_swap(&x, &y);

	printf("Swaped 'a' value: %i\n", x);
	printf("Swaped 'b' value: %i\n", y);
}
*/
