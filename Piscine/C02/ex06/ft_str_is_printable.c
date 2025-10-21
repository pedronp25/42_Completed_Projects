/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:51:40 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 16:18:14 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] < ' ' || str[x] > '~')
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
	char	*a = "Printable123";
	char	*b = "Non-printable\t";
	char	*c = "";

	printf("This should return '1': %i\n", ft_str_is_printable(a));
	printf("This should return '0': %i\n", ft_str_is_printable(b));
	printf("This should return '1': %i\n", ft_str_is_printable(c));
}
*/
