/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:58:32 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/11 19:30:26 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	x = nb;
	while (nb > 1)
	{
		x *= nb - 1;
		nb--;
	}
	return (x);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(4));
}
*/
