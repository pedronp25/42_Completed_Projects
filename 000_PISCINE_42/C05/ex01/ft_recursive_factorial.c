/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:03:56 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/11 19:30:48 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_recursive_factorial(1));
}
*/
