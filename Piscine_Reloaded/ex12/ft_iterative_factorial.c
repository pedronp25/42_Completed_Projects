/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:28:25 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/07 00:53:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	x = 1;
	while (nb > 1)
	{
		x *= nb;
		nb--;
	}
	return (x);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_iterative_factorial(12));
}
*/
