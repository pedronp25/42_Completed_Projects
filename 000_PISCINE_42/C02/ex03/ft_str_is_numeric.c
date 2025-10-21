/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:25:46 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 16:11:13 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] < '0' || str[x] > '9')
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
	char	*a = "123456789";
	char	*b = "These are not numbers --> / :";
	char	*c = "";

	printf("This should return '1': %i\n", ft_str_is_numeric(a));
	printf("This should return '0': %i\n", ft_str_is_numeric(b));
	printf("This should return '1': %i\n", ft_str_is_numeric(c));
}
*/
