/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:59:00 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/02 18:02:34 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	x = 1;
	while (x * x < nb)
	{
		x++;
	}
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
