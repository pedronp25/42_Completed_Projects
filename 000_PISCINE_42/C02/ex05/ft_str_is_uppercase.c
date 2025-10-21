/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:43:57 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 17:12:27 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] < 'A' || str[x] > 'Z')
		{
			return (0);
		}
		x++;
	}
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*a = "UPERCASE";
	char	*b = "lowercase";
	char	*c = "";
	char	*d = "0123456789";

	printf("This should return '1': %i\n", ft_str_is_uppercase(a));
	printf("This should return '0': %i\n", ft_str_is_uppercase(b));
	printf("This should return '1': %i\n", ft_str_is_uppercase(c));
	printf("This should return '0': %i\n", ft_str_is_uppercase(d));
}
*/
