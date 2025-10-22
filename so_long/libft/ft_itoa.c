/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:57:02 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/17 19:44:42 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		is_neg;

	is_neg = 0;
	size = int_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		is_neg = 1;
	}
	while (size > is_neg)
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	int_size(int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		x++;
	}
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
	int	x;

	x = -56789;
	printf("String returned: %s\n", ft_itoa(x));
}
*/
