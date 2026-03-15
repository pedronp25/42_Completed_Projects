/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:09:09 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 02:33:50 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*
int	main(void)
{
	char	x;
	char	y;

	x = 'B';
	y = 'b';

	printf("Uppercase letter: %c\n", x);
	printf("Lowercase letter: %c\n", y);

	x = ft_tolower(x);
	y = ft_tolower(y);

	printf("Uppercase letter: %c\n", x);
	printf("Lowercase letter: %c\n", y);
}
*/
