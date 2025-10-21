/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:21:44 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 14:35:43 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (dest[x])
		x++;
	y = 0;
	while (src[y] && y < nb)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[] = "This is the beggining. ";
	char	b[] = "E isto é o fim.";
	int	bytes = 5;

	printf("%s\n", ft_strncat(a, b, bytes));

	char	c[] = "This is the beggining. ";
	char    d[] = "E isto é o fim.";

	printf("%s\n", strncat(c, d, bytes));
}
*/
