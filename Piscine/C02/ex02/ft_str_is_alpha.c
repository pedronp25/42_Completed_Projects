/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:44:16 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 16:05:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] < 'A' || (str[x] > 'Z' && str[x] < 'a') || str[x] > 'z')
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
	char	*a = "Alpha";
	char	*b = "~Non_Alpha?";
	char	*c = "";

	printf("This should return '1': %i\n", ft_str_is_alpha(a));
	printf("This should return '0': %i\n", ft_str_is_alpha(b));
	printf("This should return '1': %i\n", ft_str_is_alpha(c));
}
*/
