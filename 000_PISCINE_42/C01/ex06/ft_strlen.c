/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:10:11 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/27 19:39:20 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (*str != '\0')
	{
		str++;
		x++;
	}
	return (x);
}

/*
int	main(void)
{
	char	*a = "Olá, boa noite!";
	char	*b = "0123456789";

	ft_strlen(a);

	printf("Char count 'a': %d\n", ft_strlen(a));

	ft_strlen(b);

	printf("Char count 'b': %d\n", ft_strlen(b));
}
*/
