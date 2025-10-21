/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:48:38 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/07 00:53:44 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_recursive_factorial(0));
}
*/
