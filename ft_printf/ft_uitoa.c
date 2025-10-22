/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:52:57 by pedromig          #+#    #+#             */
/*   Updated: 2025/05/06 01:05:08 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_size(unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		size;

	size = uint_size(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	uint_size(unsigned int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

/*
int	main(void)
{
	unsigned int	x;

	x = 0;
	printf("String returned: %s\n", ft_uitoa(x));
}
*/
