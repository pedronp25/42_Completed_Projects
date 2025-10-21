/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:39:49 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/10 17:28:14 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char	c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	x;
	int	neg_count;
	int	res;

	x = 0;
	res = 0;
	neg_count = 0;
	while (ft_isspace(str[x]))
		x++;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg_count++;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = (str[x] - '0') + res * 10;
		x++;
	}
	if ((neg_count % 2) != 0)
		res = -res;
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "   ---+--+1234ab67";
	char	b[] = " -42";
	char	c[] = " -+-++77";
	char	d[] = " - + - + 101";

	printf("%i\n", ft_atoi(a));
	printf("%i\n", ft_atoi(b));
	printf("%i\n", ft_atoi(c));
	printf("%i\n", ft_atoi(d));
}
*/
