/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:29:07 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/11 19:31:09 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	x = 0;
	while (x * x < nb)
		x++;
	if (x * x == nb)
		return (x);
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_sqrt(81));
}
*/
