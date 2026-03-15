/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:30:05 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/11 22:31:51 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	meow;
	int		x;
	int		neg;

	meow = 0;
	x = 0;
	neg = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == ' ')
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			neg = 1;
		x++;
	}
	while (ft_isdigit(nptr[x]))
	{
		meow = meow * 10 + (nptr[x] - 48);
		x++;
	}
	if (neg == 1)
		meow = -meow;
	return (meow);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	printf("Returned long: %l\n", ft_atol(argv[1]));
}
*/
