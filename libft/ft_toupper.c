/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:05 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 02:34:00 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	char	x;
	char	y;

	x = 'a';
	y = 'A';

	printf("Lowercase letter: %c\n", x);
	printf("Uppercase letter: %c\n", y);

	x = ft_toupper(x);
	y = ft_toupper(y);

	printf("Lowercase letter: %c\n", x);
	printf("Uppercase letter: %c\n", y);
}
*/
