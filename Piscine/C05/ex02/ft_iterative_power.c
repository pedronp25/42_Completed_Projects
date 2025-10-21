/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:12:53 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/11 19:28:18 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	x;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	x = 1;
	while (power > 0)
	{
		x *= nb;
		power--;
	}
	return (x);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_power(0, 5));
}
*/
