/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:17:21 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/11 21:32:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	meow;
	int	x;
	int	neg;

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

	printf("Returned int: %i\n", ft_atoi(argv[1]));
}
*/
