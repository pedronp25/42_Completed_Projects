/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:36:33 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 16:14:34 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] < 'a' || str[x] > 'z')
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
	char	*a = "lowercase";
	char	*b = "UPERCASE";
	char	*c = "";
	char	*d = "0123456789";

	printf("This should return '1': %i\n", ft_str_is_lowercase(a));
	printf("This should return '0': %i\n", ft_str_is_lowercase(b));
	printf("This should return '1': %i\n", ft_str_is_lowercase(c));
	printf("This should return '0': %i\n", ft_str_is_lowercase(d));
}
*/
